constants_nodes = (
    'A',
    'B',
    'C',
    'R',
    'P'
)

numbers_nodes = len(constants_nodes)
adj = {}
parent = {}
for i in range(numbers_nodes):
    parent[constants_nodes[i]] = -1

input_line = input().split(' ')
is_right_r = input_line[1] == '1'
is_right_p = input_line[0] == '1'

def dfs(node) -> None:
    if adj[node]:
        for next_node in adj[node]:
            if parent[next_node] != -1:
                continue
            parent[next_node] = node
            dfs(next_node)
    else:
        print(node)

for i in range(numbers_nodes):
    adj[constants_nodes[i]] = []

if is_right_p:
    adj['P'].append('R')
else:
    adj['P'].append('C')

if is_right_r:
    adj['R'].append('A')
else:
    adj['R'].append('B')

dfs('P')
