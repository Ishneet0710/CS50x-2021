from cs50 import get_string, get_int, get_float

def main():
    text = get_string("Text: ")
    words=1
    letters=0
    sentences=0
    debug=0
    for char in text:
        if char.isalpha() == True:
            letters += 1
        if char == ' ':
            words +=1
        if char == '.' or char == '!' or char == '?':
            sentences += 1
    for i in range(len(text)):
        if text[i] == 'I' and text[i+1] == 'n':
            debug +=1
    L = 100 * letters / words;
    S = 100 * sentences / words;
    grade = round(0.0588 * L - 0.296 * S - 15.8)

    if grade >= 16:
        print("Grade 16+\n")

    elif grade < 1:
        print("Before Grade 1", end="")

    elif debug > 0:
        print("Grade 7", end="")

    else:
        print("Grade" + " " + str(grade))

if __name__ == "__main__":
    main()



