Rutinakete(int matrix[3][20], int fila, int limit){
    int i, resultado;
    resultado = 0;
    i = 1;
    do{
        if (matrix[fila][i] == 5) resultado++;
        i++;
    }
    while (i < limit);
    return resultado;
}
