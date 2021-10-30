def floodfill(matrix, x, y):
    #"hidden" stop clause - not reinvoking for "c" or "b", only for "a".
    if matrix[x][y] == "a":  
        matrix[x][y] = "c" 
        #recursively invoke flood fill on all surrounding cells:
        if x > 0:
            floodfill(matrix,x-1,y)
        if x < len(matrix[y]) - 1:
            floodfill(matrix,x+1,y)
        if y > 0:
            floodfill(matrix,x,y-1)
        if y < len(matrix) - 1:
            floodfill(matrix,x,y+1)