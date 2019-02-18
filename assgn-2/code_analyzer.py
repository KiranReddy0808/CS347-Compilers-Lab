import re

comment_spans = []
classes = {}
inherited_classes = {}
functions = {}
constructors = {}
op_over_functions = {}
objects = []

def find_comments(source):
	pos = 0
	match = re.search(r'\/\*[\s\S]*?\*\/|\/\/.*\n', source)
	while match:
		comment_spans.append((pos+match.start(), pos+match.end()))
		pos = pos + match.end()
		match = re.search(r'\/\*[\s\S]*?\*\/|\/\/.*\n', source[pos:])

def in_comments(pos):
	for span in comment_spans:
		if pos >= span[0] and pos < span[1]:
			return span[1]
		if pos < span[0]:
			return -1
	return -1

def find_classes(source):
	pos = 0
	class_start_match = re.search(r'class\s+([a-zA-Z_]\w*)\s*\{',source)
	while class_start_match:
		comment_check = in_comments(class_start_match.start())
		if comment_check == -1:
			end_pos = pos+class_start_match.end()
			# print(end_pos)
			class_end_match = re.search(r'\}\s*\;', source[end_pos:])
			if class_end_match:
				while class_end_match:
					end_pos = end_pos + class_end_match.end()
					# print(end_pos)
					end_comment_check = in_comments(end_pos)
					# print(end_comment_check)
					if end_comment_check==-1:
						break
					else:
						end_pos = end_comment_check
						# print(end_pos)
						class_end_match = re.search(r'\}\s*\;', source[end_pos:])
				if class_end_match:
					classes[class_start_match.group(1)] = (pos+class_start_match.start(), end_pos)
					pos = end_pos
				else:
					print ('Error in ', class_start_match.group(), '\nMissing };')
					return
			else:
				print ('Error in ', class_start_match.group(), '\nMissing };')
				return
		else:
			pos = comment_check
		class_start_match = re.search(r'class\s+([a-zA-Z_]\w*)\s*\{',source[pos:])

def find_inherited(source):
	pos = 0
	class_start_match = re.search(r'class\s+([a-zA-Z_]\w*)\s*\:\s*([\s\w,]*?)\{',source)
	while class_start_match:
		comment_check = in_comments(class_start_match.start())
		if comment_check == -1:
			end_pos = pos+class_start_match.end()
			# print(end_pos)
			class_end_match = re.search(r'\}\s*\;', source[end_pos:])
			if class_end_match:
				while class_end_match:
					end_pos = end_pos + class_end_match.end()
					# print(end_pos)
					end_comment_check = in_comments(end_pos)
					# print(end_comment_check)
					if end_comment_check == -1:
						break
					else:
						end_pos = end_comment_check
						# print(end_pos)
						class_end_match = re.search(r'\}\s*\;', source[end_pos:])
				if class_end_match:
					parent_class_names = []
					error = False
					for parent_class in class_start_match.group(2).split(','):
						parent_class_defn = parent_class.split()
						if len(parent_class_defn) == 1:
							parent_class_names.append(parent_class_defn[0])
						elif len(parent_class_defn) == 2:
							if (parent_class_defn[0] in ['public', 'private', 'protected']):
								parent_class_names.append(parent_class_defn[1])
							else:
								print ('Error in ', class_start_match.group(), '\nParent classes access definitions')
								error = True
					for name in parent_class_names:
						if not is_class(name):
							error = True
							print ('Error in ', class_start_match.group(), '\nParent classes do not exist')
							break
					if not error:
						inherited_classes[class_start_match.group(1)] = (pos+class_start_match.start(), end_pos, parent_class_names)
					pos = end_pos
				else:
					print ('Error in ', class_start_match.group(), '\nMissing };')
					return
			else:
				print ('Error in ', class_start_match.group(), '\nMissing };')
				return
		else:
			pos = comment_check
		class_start_match = re.search(r'class\s+([a-zA-Z_]\w*)\s*\:\s*([\s\w,]*?)\{',source[pos:])

def is_class(class_name):
	if class_name in classes.keys() or class_name in inherited_classes.keys():
		return True
	else:
		return False

def in_class(pos):
	for class_name in classes.keys():
		span = classes[class_name]
		if pos >= span[0] and pos < span[1]:
			return class_name
	for class_name in inherited_classes.keys():
		span = inherited_classes[class_name]
		if pos >= span[0] and pos < span[1]:
			return class_name
	return False

def match_flower(pos):
	flower_stack = ['{']
	for flower in re.finditer(r'(\{|\})', source[pos:]):
		if (flower.group()=='{'):
			flower_stack.append('{')
		else:
			if (flower_stack[-1]=='{'):
				flower_stack.pop()
				if (len(flower_stack)==0):
					return pos+flower.end()
	else:
		return -1

def find_func_constr(source):
	func_matches = re.finditer(r'([a-zA-Z_]\w*\s*\:\:)?\s*([a-zA-Z_]\w*)\s*\(([\s\w,*]*)\)\s*\{', source)
	for func_match in func_matches:
		if in_comments(func_match.start())==-1:
			closing_flower = match_flower(func_match.end())
			if closing_flower == -1:
				print("Error in ", func_match.group(), "\nMissing }")
				continue
			if func_match.group(1):
				class_name = func_match.group(1).split('::')[0].split()[0]
				if is_class(class_name):
					if class_name == func_match.group(2):
						func_name = func_match.group(2)
						func_details = (func_match.start(),closing_flower,func_match.group(3))
						if func_name in functions.keys():
							constructors[func_name].append(func_details)
						else:
							constructors[func_name]=[func_details]
					else:
						func_name = class_name+'::'+func_match.group(2)
						func_details = (func_match.start(),closing_flower,func_match.group(3))
						if func_name in functions.keys():
							functions[func_name].append(func_details)
						else:
							functions[func_name]=[func_details]
				else:
					print("Error in ", func_match.group(), "\nClass: ", class_name, " does not exist")
			else:
				class_name = in_class(closing_flower)
				if class_name:
					if class_name == func_match.group(2):
						func_name = func_match.group(2)
						func_details = (func_match.start(),closing_flower,func_match.group(3))
						if func_name in functions.keys():
							constructors[func_name].append(func_details)
						else:
							constructors[func_name]=[func_details]
					else:
						func_name = class_name+'::'+func_match.group(2)
						func_details = (func_match.start(),closing_flower,func_match.group(3))
						if func_name in functions.keys():
							functions[func_name].append(func_details)
						else:
							functions[func_name]=[func_details]
				else:
					func_name = func_match.group(2)
					func_details = (func_match.start(),closing_flower,func_match.group(3))
					if func_name in functions.keys():
						functions[func_name].append(func_details)
					else:
						functions[func_name]=[func_details]
		else:
			continue

def find_objects(source):
	obj_matches = re.finditer(r'([a-zA-Z_]\w*)\s+([a-zA-Z_]\w*)\s*(\([\s\w,*]*\))?\s*;',source)
	for obj_match in obj_matches:
		# print(obj_match.groups())
		if in_comments(obj_match.start())==-1:
			if is_class(obj_match.group(1)):
				objects.append((obj_match.group(2), obj_match.start(), obj_match.end(), obj_match.group(1), obj_match.group(3)))
		else:
			continue

def find_op_overload(source):
	func_matches = re.finditer(r'([a-zA-Z_]\w*\s*\:\:)?\s*operator\s*(\S+?)\s*\(([\s\w\,\*\&]*)\)\s*(const)?\s*\{', source)
	for func_match in func_matches:
		if in_comments(func_match.start())==-1:
			closing_flower = match_flower(func_match.end())
			if closing_flower == -1:
				print("Error in ", func_match.group(), "\nMissing }")
				continue
			if func_match.group(1):
				class_name = func_match.group(1).split('::')[0].split()[0]
				if is_class(class_name):
					func_name = class_name+'::'+'operator'+func_match.group(2)
					if func_match.group(4):
						func_name+=' '+func_match.group(4)
					func_details = (func_match.start(),closing_flower,func_match.group(3))
					if func_name in op_over_functions.keys():
						op_over_functions[func_name].append(func_details)
					else:
						op_over_functions[func_name]=[func_details]
				else:
					print("Error in ", func_match.group(), "\nClass: ", class_name, " does not exist")
			else:
				class_name = in_class(closing_flower)
				if class_name:
					func_name = class_name+'::'+'operator'+func_match.group(2)
					if func_match.group(4):
						func_name+=' '+func_match.group(4)
					func_details = (func_match.start(),closing_flower,func_match.group(3))
					if func_name in op_over_functions.keys():
						op_over_functions[func_name].append(func_details)
					else:
						op_over_functions[func_name]=[func_details]
				else:
					func_name = 'operator'+func_match.group(2)
					if func_match.group(4):
						func_name+=' '+func_match.group(4)
					func_details = (func_match.start(),closing_flower,func_match.group(3))
					if func_name in op_over_functions.keys():
						op_over_functions[func_name].append(func_details)
					else:
						op_over_functions[func_name]=[func_details]
		else:
			continue

source_file = open("input.txt", "r")
source = source_file.read()
source_file.close()

find_comments(source)
# print(comment_spans)

find_classes(source)
# print(classes)

find_inherited(source)
# print(inherited_classes)

find_func_constr(source)
# print(functions)
# print(constructors)

find_objects(source)
# print(objects)

find_op_overload(source)
# print (op_over_functions)

num_func = 0
for func in op_over_functions.keys():
	num_func += len(op_over_functions[func])

num_constr = 0
for constr in constructors.keys():
	num_constr += len(constructors[constr])

output = '1) Objects declaration\t\t\t\t\t\t: '+str(len(objects))+'\n2) Class definition\t\t\t\t\t\t\t: '+str(len(classes.keys())+len(inherited_classes.keys()))+'\n3) Constructor definition\t\t\t\t\t: '+str(len(constructors.keys()))+'\n4) Inherited Class definition\t\t\t\t: '+str(len(inherited_classes.keys()))+'\n5) Operator Overloaded function definition\t: '+str(num_func)
output_file = open("output.txt", "w")
output_file.write(output)
output_file.close()