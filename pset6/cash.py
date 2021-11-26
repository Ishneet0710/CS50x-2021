from cs50 import get_string, get_int, get_float

def main():
    while True:
        x = get_float("Change owed: ")
        if x>=0:
            break
    cents = round(x*100)
    count = 0
    while cents >=25 :
        cents -= 25
        count += 1
    while cents >=10 :
        cents -= 10
        count += 1
    while cents >=5 :
        cents -= 5
        count += 1
    while cents >=1 :
        cents -= 1
        count += 1
    print(count)

if __name__ == "__main__":
    main()
