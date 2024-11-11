from collections import Counter

def getAnagramPeriod(input_str: str) -> int:
    n = len(input_str)

#Try all possible lengths of the substring s
    for length in range(1, n + 1):
#If the total length of the string is divisible by this length
        if n % length == 0:
#Split the string into chunks of length
            chunks = [input_str[i:i + length] for i in range(0, n, length)]
#Check if all chunks are anagrams of the first chunk
            first_chunk_counter = Counter(chunks[0])
            if all(Counter(chunk) == first_chunk_counter for chunk in chunks):
                return length
    
    return n  # If no smaller period is found, return the length of the string

#Example usage
input_str = "ababbaab"
print(getAnagramPeriod(input_str))  # Expected output: 2

input_str = "abcbcacba"
print(getAnagramPeriod(input_str))  # Expected output: 3