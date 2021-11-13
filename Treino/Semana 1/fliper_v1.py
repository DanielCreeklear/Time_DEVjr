input_line = input().split(' ')
is_right_r = input_line[1] == '1'
is_right_p = input_line[0] == '1'

if not is_right_p:
    print('C')
else:
    if not is_right_r:
        print('B')
    else:
        print('A')