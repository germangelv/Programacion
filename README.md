   Modelo de Parcial para Programacion 1 (Programacion II) v0.26 03/12/2015
   
   Este modelo implementa las funciones elementales del TP1, TP2, TP3, incluyendo muchas de parciales
   
   CAMBIOS:
   
   0.30 Habria que implementar algun ejemplo completo de TDA PILA, COLA LISTA y los menues
   No se implemento porque la promocione con 10
   
   0.26 Implemente muchas de matrices colgadas, decodificar y gregue las que faltaban de cadenas
   
   0.25 Implementacion de str_rchr y pruebas de todas las funciones
   
   0.24 Implementacion de funciones para mostrar y guardar binarios y texto y correcciones
   
   0.23 Implementacion de abs, max, y funciones de archivos binarios y de texto
   
   0.22 Correccion de todos los warnings, Implementacion de str_tok, str_spn, str_cspn, str_brk, str_cmpi, str_ncmp.
   
   0.21 Implementacion de desplazar_cadena, modificar_cadena, invertir_cadena, proxima_palabra, fin_palabra.
   
   0.20 Implementacion de esAlfanumerico, esPar, esImpar, pila circular y cola circular
   
   0.19 Correcion para que el Main de Arbol funcione y normalizacion de todas las funciones de los .h, .c
   
   0.15 Correcciones y cambio de estructura t_dato para que ARBOL funcione y muchos cambios de nombres de funciones
   
   0.10 Implementacion de ARBOL (t_nodo se diferencio de TDAs y TDA Arbol)
   
   0.7  Implementacion de Lista
   
   0.5  Implementacion de Cola Estatica y Dinamica y correccion de errores de Pila
   
   0.4  Implementacion de Pila Estatica y Dinamica
   
   0.3  Implementacion de Menues y cambios de estructuras.
   
   0.2  Implementacion de operaciones de Matrices y correccion de errores.
   
   0.1  Este proyecto me lo encontre con la Implementacion de Matematica, Fechas y Vectores.
   
   MATEMATICAS:
   
   .h:
   esPar, esImpar, abs, max
   
   .c:
    factorial, combinatorio, e_a_la_x, raizcuadrada, fibonacci, seno, clasificacion, multiplicacion,
    cocienteyresto, suma_primeros_naturales, suma_primeros_pares, suma_pares_menores, primo, multiplicacion_rusa,
    parte_entera.
    
   CADENAS:
   
   .h:
    esBlanco, esCaracter, aMayusc, aMinusc, esDigito, esAlfanumerico,
    
   .c:
    normalizar, reemplazar, cuentochar, anagrama, i_toa, a_toi, mem_move, mem_cpy, mem_cmp, strcat, str_cpy, str_lwr,
    str_upr, str_chr, str_str, str_cmp, str_len, to_lower, to_upper,desplazar_cadena, modificar_cadena,
    invertir_cadena, proxima_palabra, fin_palabra, str_tok, str_spn, str_cspn, str_brk, str_cmpi, str_ncmp,
    eliminarSubCad.
    
   VECTORES:
   
    tam, cargar_vector, mostrar_vector, insertar_en_pos, insertar_en_orden_vec, desplazamiento_derecha,
    desplazamiento_izquierda, eliminar_de_posicion, eliminar_1era_aparicion, eliminar_todas_apariciones.
    
   MATRICES:
   
   orden, cargar_matriz, mostrar_matriz, simetrica, identidad, suma_princ, suma_secund, suma_arriba_princ, suma_abajo_princ, suma_arriba_secund, suma_abajo_secund, transponer.
   
   FECHAS:
   
   .h:
    esBisiesto
    
   .c:
    es_fecha_valida, es_fecha_juliana_valida, ingresar_fecha, ingresar_fecha_juliana_valida, cant_dias_mes, dia_sig, sumar_dias,
    restar_dias, f_juliana, f_gregoriana, comp_fechas, dias_a, dif_fechas, dia_semana, t_fecha obtener_fecha_maq.
    
   PILA:
   
   Esta la implementacion estatica (s), dinamica (d) y circular (c)
   
    crear_pila_s, pila_llena_s, poner_en_pila_s, sacar_de_pila_s, ver_el_tope_s, pila_vacia_s, vaciar_pila_s.
    crear_pila_d, pila_llena_d, poner_en_pila_d, sacar_de_pila_d, ver_el_tope_d, pila_vacia_d, vaciar_pila_d.
    crear_pila_c, pila_llena_c, poner_en_pila_c, sacar_de_pila_c, ver_el_tope_c, pila_vacia_c, vaciar_pila_c.
    
   COLA:
   
   Esta la implementacion estatica (s), dinamica (d) y circular (c)
   
    crear_cola_s, cola_llena_s, cola_vacia_s, poner_en_cola_s, vaciar_cola_s, ver_primero_cola_s, sacar_de_cola_s.
    crear_cola_d, cola_llena_d, cola_vacia_d, poner_en_cola_d, vaciar_cola_d, ver_primero_cola_d, sacar_de_cola_d.
    crear_cola_c, cola_llena_c, cola_vacia_c, poner_en_cola_c, vaciar_cola_c, ver_primero_cola_c, sacar_de_cola_c.
    
   LISTA:
   
    crear_lista, lista_llena, lista_vacia, vaciar_lista, vaciar_lista_contarygrabar_en_arch, insertar_al_comienzo,
    insertar_al_final, insertar_en_orden_lista, buscar_en_lista_ordenada, buscar_en_lista_no_ordenada, ordenar_x_burbuja,
    eliminar_no_duplicados_lista_ordenada, eliminar_no_duplicados_lista_no_ordenada, eliminar_duplicados_lista_no_ordenada,
    eliminar_duplicados_lista_ordenada.
    
   ARBOL:
   
    mostrar_nodo_arbol, abrirArchivo, leerTxtEnArbol, en_orden, pre_orden, pos_orden, buscarR, crear_arbol, arbol_lleno,
    poner_en_arbol, eliminar_arbol, eliminar_arbol_y_contar, eliminar_arbol_y_contar_y_almacenar, eliminar_arbol_hasta_altura,
    eliminar_hojas, altura_arbol, contar_nodos_arbol, contar_nodos_hasta_altura, es_balanceado, es_completo,
    determinar_si_es_completo, determinar_si_es_balanceado, determinar_si_es_AVL, contar_hoja, contar_y_mostrar_hojas,
    contar_nodos_internos, contar_nodos_Internos_con_HD, contar_nodos_Internos_con_HI, contar_nodos_rama_I, contar_nodos_rama_D,
    contar_todos_nodos_con_HI, contar_todos_nodos_con_HD, contar_nodos_hasta_Hmenos1, contar_nodos_desdeH,
    mostrar_nodo_y_contar_de_H, contar_nodos_de_H, contar_nodos_rama_I, contar_nodos_rama_D, mostrar_losdeH, mostrar_hastaH,
    mostrar_desdeH, cargar_arbol_archivo_bin, insertar_en_arbol_recursivo.
    
FUNCIONA

   ARCHIVOS:
   abrir_archivo, mostrar_persona,cargar_archivo_texto_variable,
   cargar_archivo_binario_fijo, mostrar_archivo_binario_fijo,
   mostrar_archivo_texto_variable.
