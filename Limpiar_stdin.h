int limpiar_stdin(){
    int c;
        do {
            c = getchar();
            }
        while (c != '\n' && c != EOF);
    return 0;    
}