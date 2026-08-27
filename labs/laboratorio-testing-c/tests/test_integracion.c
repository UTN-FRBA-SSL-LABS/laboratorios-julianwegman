#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */
void test_compra_con_descuento(void) {
    Carrito c;
    carrito_init(&c);
    Producto pan = {"Pan", 200, 3};
    Producto leche = {"Leche", 350, 2};
    carrito_agregar(&c, pan);
    carrito_agregar(&c, leche);
    int total = carrito_total(&c);  
    int total_con_descuento = carrito_descuento(total, 10);
    ASSERT_IGUAL(1300, total);
    ASSERT_IGUAL(1170, total_con_descuento);  
}
/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_agregar_hasta_llenar() */
void test_agregar_hasta_llenar(void) {
    Carrito c;
    carrito_init(&c);
    for (int i = 0; i < MAX_ITEMS; i++) {
        Producto p = {"Producto", 100, 1};
        carrito_agregar(&c, p);
    }
    Producto p ={"Producto", 100, 1};
    int a=carrito_agregar(&c,p);
    ASSERT_IGUAL(0, a);
}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
     test_compra_con_descuento();  
     test_agregar_hasta_llenar();  
    RESUMEN();
    return EXIT_CODE();
}
