#!/usr/bin/env python

import os
from urllib import parse

def main():
    readme = ""
    content = ""
    
    directories = [];
    solveds = [];

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
            if category not in solveds:
                number = category.split('.')[0]
                name = category.split('.')[1]
                content += "`{}. {} [\U0001F517]({})`\n\n".format(number, name, parse.quote(os.path.join(root, file)))
                solveds.append(category)
                print("category : " + category)

    for value in tier.values():
        total += value
        
    readme += ("```C\n" + 
               "void Baekjoon() {{\n\n" + 
               "    static int total = {};\n\n".format(total) + 
               "    enum {{\n" + 
               "        BRONZE = {},\n".format(tier["Bronze"]) + 
               "        SILVER = {},\n".format(tier["Silver"]) +
               "        GOLD = {},\n".format(tier["Gold"]) + 
               "        PLATINUM = {},\n".format(tier["Platinum"]) + 
               "        DIAMOND = {},\n".format(tier["Diamond"]) + 
               "        RUBY = {}\n}};\n\n".format(tier["Ruby"]) + 
               "    printf(problems);\n" + 
               "```\n" + content + ">")
    
    readme += content
    
    with open("README.md", "w") as fd:
        fd.write(readme)
        
if __name__ == "__main__":
    main()
