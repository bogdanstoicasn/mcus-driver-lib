import os
import shutil

REPO_DIR = os.path.dirname(os.path.abspath(__file__))

libs = [item for item in os.listdir(REPO_DIR) if os.path.isdir(os.path.join(REPO_DIR, item)) and not item.startswith('.')]

if not libs:
    print('No libraries found')
    exit(1)

print("Available MCU libraries:")
for i, lib in enumerate(libs):
    print(f"{i+1}. {lib}")

try:
    lib_index = int(input("Enter the number of the library you want to manage: ")) - 1
    if lib_index < 0 or lib_index >= len(libs):
        raise ValueError
except ValueError:
    print("Invalid input")
    exit(1)

lib = libs[lib_index]
LIB_DIR = os.path.join(REPO_DIR, lib)
print(f"Selected library: {lib}")

confirm = input(f"You selected {lib}. Do you want to delete al other libs? (y/n): ")
if confirm.lower() != 'y':
    print("Operation cancelled!")
    exit(0)

for item in libs:
    if item != lib:
        shutil.rmtree(os.path.join(REPO_DIR, item))
        print(f"Deleted {item}")

print("Operation completed!")


