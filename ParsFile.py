import os
import glob
import re

SIZE_SUB_STRING = 10
pathFileSave = r"C:\Users\user\Desktop\GoogleProject\GoogleProject\GoogleProject"
path = r'C:\Users\user\Desktop\GoogleProject\GoogleProject\GoogleProject\google'
dictKeysAndSentences = {}


def addDict(key: str, file: str, line: int):
    try:
        if line not in dictKeysAndSentences[key][file]:
            dictKeysAndSentences[key][file].append(line)
    except KeyError:
        try:
            dictKeysAndSentences[key][file] = [line]
        except KeyError:
            dictKeysAndSentences[key] = {}
            dictKeysAndSentences[key][file] = [line]


def parseSubString(line):
    return [line[i: j] for i in range(len(line) - 1)
            for j in range(i + 1, len(line)) if len(line[i: j]) < 11 and "\n" not in line[i: j]]


def writeData():
    with open(pathFileSave + r'\fileData.txt', 'w') as f:
        for key, val in dictKeysAndSentences.items():
            for k, v in val.items():
                for i in sorted(v):
                    f.write(f'{key};{k};{i}\n')


for file in glob.glob(os.path.join(path, '*.txt')):
    fileName = os.path.basename(file).split(".")[0]
    i=0
    print(fileName)
    with open(file) as f:
        for  line in f.readlines():
            line = re.sub('[\W]+[\s]*', ' ', line).lower()
            for j in parseSubString(line):
                addDict(j, fileName, i)
            i+=1
    writeData()


