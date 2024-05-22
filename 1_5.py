haystack = "mississipi"
needle = "issi"
bool = False
counter = 0
index = 0 
print("len(needle)", len(needle))
print("len(haystack)-len(needle)", len(haystack)-len(needle))
if needle in haystack:
    for j in range(len(haystack)-len(needle)+1):
        for i in range(len(needle)):
            print(j,i)
            if not bool:
                counter = 0
            if haystack[j] == needle[i]:
                print(haystack[j], needle[i])
                bool = True
                counter += 1
                if counter == len(needle):
                    print("ovdje sam")
                    index = j-len(needle)+1
                break
            else:
                bool = False
            print("david")
            
print(index)