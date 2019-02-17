import re

comment_spans = []
classes = {}
inherited_classes = {}
functions = {}

def find_comments(source):
	pos = 0
	match = re.search(r'\/\*[\s\S]*?\*\/|\/\/.*\n', source)
	while match:
		comment_spans.append((pos+match.span()[0], pos+match.span()[1]))
		pos = pos + match.span()[1]
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
		comment_check = in_comments(class_start_match.span()[0])
		if comment_check == -1:
			end_pos = pos+class_start_match.span()[1]
			# print(end_pos)
			class_end_match = re.search(r'\}\s*\;', source[end_pos:])
			if class_end_match:
				while class_end_match:
					end_pos = end_pos + class_end_match.span()[1]
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
					classes[class_start_match.group(1)] = (pos+class_start_match.span()[0], end_pos)
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
		comment_check = in_comments(class_start_match.span()[0])
		if comment_check == -1:
			end_pos = pos+class_start_match.span()[1]
			# print(end_pos)
			class_end_match = re.search(r'\}\s*\;', source[end_pos:])
			if class_end_match:
				while class_end_match:
					end_pos = end_pos + class_end_match.span()[1]
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
						inherited_classes[class_start_match.group(1)] = (pos+class_start_match.span()[0], end_pos, parent_class_names)
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
	if class_name in classes.keys() + inherited_classes.keys():
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

source_file = open("test1.txt", "r")
source = source_file.read()

# find_comments(source)
# print(comment_spans)

# find_classes(source)
# print(classes)

# find_inherited(source)
# print(inherited_classes)

#print(re.findall(r'([a-zA-Z_]\w*\s*\:\:)?\s*([a-zA-Z_]\w*)\s*\(([\s\w,*]*)\)\s*\{', source))

source_file.close()