line = input("Enter a sentence : ").lower().replace(
    'there exiest someone who', 'someone').split()
print(line)
keywords = ['likes', 'love', 'loved', 'loves', 'like']
special = ['someone', 'everyone']
sentence = ''
if 'someone' in line:
    line[line.index('someone')] = 'x'
    sentence = "∃x"
if 'everyone' in line:
    line[line.index('everyone')] = 'x'
    sentence = "∀x"
if line[1] in keywords:
    print(f"{sentence} {line[1]} ( {line[0]}, {line[2]} )")
