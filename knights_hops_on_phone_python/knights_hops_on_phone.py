import sys

NEIGHBORS_MAP = {
    1: (6, 8),
    2: (7, 9),
    3: (4, 8),
    4: (3, 9, 0),
    5: tuple(),  # 5 has no neighbors
    6: (1, 7, 0),
    7: (2, 6),
    8: (1, 3),
    9: (2, 4),
    0: (4, 6),
    }

def neighbors(position):
    return NEIGHBORS_MAP[position]

def count_sequences(starting_position, num_hops):
    prior_case = [1] * 10
    current_case = [0] * 10
    current_num_hops = 1
    
    while current_num_hops <= num_hops:
        print(prior_case)
        current_case = [0] * 10
        current_num_hops += 1

        for position in range(0, 10):
            for neighbor in neighbors(position):
                current_case[position] += prior_case[neighbor]
        prior_case = current_case
    return current_case[starting_position]

if __name__ == "__main__":
    print(count_sequences(1,5))
    
