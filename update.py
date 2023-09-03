import os
from urllib import parse

HEADER = "# Baekjoon\n"    # Enter the title you want
DESC = "Baekjoon Algorithm Practice\n"    # Enter the description you want
TOTAL_TABLE_HEADER = "| Total |\n|:-----:|\n"
TIER_TABLE_HEADER = "| Bronze | Silver | Gold | Platinum | Diamond | Ruby |\n|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|\n"
PROBLEM_TABLE_HEADER = "| No. | Problem | Link |\n|:-----:|:-----:|:-----:|\n"

def main():
    readme = ""
    readme += HEADER
    readme += DESC
  
    problem_content = ""
    
    directories = []
    solved = []

    total = 0
    tier = {"Bronze": 0, "Silver": 0, "Gold": 0, "Platinum": 0, "Diamond": 0, "Ruby": 0}

    for root, dirs, files in os.walk("."):
        dirs.sort()
        if root == '.':
            for dir in ('.git', '.github'):
                try:
                    dirs.remove(dir)
                except ValueError:
                    pass
            continue

        category = os.path.basename(root)
        
        if category == 'images':
            continue
        
        directory = os.path.basename(os.path.dirname(root))
        
        if directory == '.':
            continue
        else:
            try:
                tier[directory] += 1
            except:
                pass

        for file in files:
            if category not in solved:
                number = category.split('.')[0]
                name = category.split('.')[1]
                problem_content += "| {}. | {} | [\U0001F517]({}) |\n".format(number, name, parse.quote(os.path.join(root, file)))
                solved.append(category)
              
    for value in tier.values():
        total += value

    readme += (TOTAL_TABLE_HEADER + "| {} |\n\n".format(total) + TIER_TABLE_HEADER +
               "| {} | {} | {} | {} | {} | {} |\n\n".format(tier['Bronze'], tier['Silver'], tier['Gold'], tier['Platinum'], tier['Diamond'], tier['Ruby']) +
               PROBLEM_TABLE_HEADER + problem_content)
    
    with open("README.md", "w") as fd:
        fd.write(readme)
        
if __name__ == "__main__":
    main()
