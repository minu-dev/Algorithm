#!/usr/bin/env python

import os
from urllib import parse

HEADER = "```C\nprintf(\"Baekjoon\");\n```\n##\n"

def main():
    readme = ""
    readme += HEADER
    content = ""
    
    directories = [];
    solveds = [];

    bronze = 0
    silver = 0
    gold = 0
    platinum = 0
    diamond = 0
    ruby = 0

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
        elif directory == "Bronze":
            bronze += 1
        elif directory == "Silver":
            silver += 1
        elif directory == "Gold":
            gold += 1
        elif directory == "Platinum":
            platinum += 1
        elif directory == "Diamond":
            diamond += 1
        elif directory == "Ruby":
            ruby += 1

        for file in files:
            if category not in solveds:
                number = category.split('.')[0]
                name = category.split('.')[1]
                content += "| {}. | {} | [\U0001F517]({}) |\n".format(number, name, parse.quote(os.path.join(root, file)))
                solveds.append(category)
                print("category : " + category)
              
    total = bronze + silver + gold + platinum + diamond + ruby
    readme += "```C\nstatic int total = {};\n```\n##\n\n```C\nenum {{\n    BRONZE = {},\n    SILVER = {},\n    GOLD = {},\n    PLATINUM = {},\n    DIAMOND = {},\n    RUBY = {}\n}};\n```\n##\n```C\nprintf(\"Problem Lists\");\n```\n##\n| No. | Problem | Link |\n|:-:|:-|:-:|\n".format(total, bronze, silver, gold, platinum, diamond, ruby)
    
    readme += content
    
    with open("README.md", "w") as fd:
        fd.write(readme)
        
if __name__ == "__main__":
    main()
