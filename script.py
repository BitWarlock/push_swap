import random

min_int = -2147483648
max_int = 2147483647

for i in range(1, 11):
    random_number = random.randint(min_int, max_int)
    print(f"{random_number}")
