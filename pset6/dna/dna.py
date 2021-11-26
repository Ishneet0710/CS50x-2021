import csv
import sys
import random

#https://www.youtube.com/watch?v=5Cv-5_zfo_Y as reference for the algorithm for the STR_count function
def STR_count(dna, STR):
    #initialise an array with len as dna with all 0's
    ans = [0] * len(dna)
    for i in range(len(dna)-len(STR),-1,-1):
        if dna[i: i+len(STR)] == STR:
            #define the base case or when the contiguous STRs are started to be counted
            if i + len(STR) > len(dna) - 1:
                ans[i] = 1
            else:
                #add the counter which represents how many contiguous STRs have already been counted in the section checked already before i
                ans[i] = 1 + ans[i + len(STR)]
    return max(ans)
    
    
    
def main():
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py error")
    with open(sys.argv[1]) as database:
        reader = csv.reader(database)
        #take only the STRs from the reader to be referred to later on
        STRs = next(reader)[1:]
        with open(sys.argv[2]) as sequences:
            dna = sequences.read()
            suspect_STR_count = []
            for STR in STRs:
                #appending the STR count for each STR into the array to be checked later on
                suspect_STR_count.append(STR_count(dna,STR))
                
        for row in reader:
            #get the name of the person
            name = row[0]
            count = []
            #getting the sample str counts for each person in the database
            for tmp in row[1:]:
                count.append(int(tmp))
                #compare the database with suspect
            if count == suspect_STR_count:
                #if match then print name of that person
                print(name)
                return
        print("No match")

if __name__ == "__main__":
    main()
