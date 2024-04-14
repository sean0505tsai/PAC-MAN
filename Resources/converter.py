with open('map1.txt', 'r') as file:
    lines = file.readlines()

with open('output.txt', 'w') as file:
    for line in lines:
        modified_line = "\t\t\t{" +  line.strip() + "},\n"
        file.write(modified_line)
