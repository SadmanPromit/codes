# Function to split the file
def split_file(file_path, part1_path, part2_path, split_at):
    with open(file_path, 'rb') as file:
        content = file.read()
        
    part1 = content[:split_at]
    part2 = content[split_at:]
    
    with open(part1_path, 'wb') as file:
        file.write(part1)
        
    with open(part2_path, 'wb') as file:
        file.write(part2)

# Function to combine the files
def combine_files(part1_path, part2_path, output_path):
    with open(part1_path, 'rb') as file:
        part1 = file.read()
        
    with open(part2_path, 'rb') as file:
        part2 = file.read()
        
    combined_content = part1 + part2
    
    with open(output_path, 'wb') as file:
        file.write(combined_content)

# Example usage
split_file('srm.exe', 'part1.exe', 'part2.exe', split_at=200000000)
# combine_files('part1.exe', 'part2.exe', 'srm.exe')
