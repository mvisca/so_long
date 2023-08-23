*mlx_data      mlx_init(void);
Inicializa la biblioteca minilibx.

int     mlx_get_screen_size(*mlx_data, *int, *int);
Obtiene el tamaño de la pantalla en punteros int width y height.

*mlx_window     mlx_new_window(*mlx_data);
Crea una nueva ventana.

int     mlx_clear_window(*mlx_data, *mlx_window);
Borra el contenido de una ventana.

mlx_put_pixel(): Dibuja un píxel en una ventana.

mlx_get_pixel(): Obtiene el color de un píxel en una ventana.

mlx_draw_line(): Dibuja una línea en una ventana.

mlx_draw_hline(): Dibuja una línea horizontal en una ventana.

mlx_draw_vline(): Dibuja una línea vertical en una ventana.

mlx_draw_rectangle(): Dibuja un rectángulo en una ventana.

mlx_draw_circle(): Dibuja un círculo en una ventana.

mlx_draw_ellipse(): Dibuja una elipse en una ventana.

mlx_put_image(): Dibuja una imagen en una ventana.

mlx_copy_image(): Copia una imagen a otra ventana.

mlx_resize_image(): Redimensiona una imagen.

mlx_get_image_size(): Obtiene el tamaño de una imagen.

mlx_put_image_to_window(): Dibuja una imagen en una ventana en una posición específica.

mlx_put_image_to_screen(): Dibuja una imagen en la pantalla en una posición específica.

mlx_get_color_depth(): Obtiene la profundidad de color de la pantalla.

mlx_set_color_depth(): Establece la profundidad de color de la pantalla.

mlx_set_rgb_color(): Establece un color RGB.

mlx_set_font(*mlx_data, "Font", 12): Establece el tipo de fuente.

mlx_string_put(*mlx_data, *mlx_window, int, int, *char, hex): Imprime un texto en la ventana.

mlx_get_rgb_color(): Obtiene un color RGB.

mlx_x_to_rgb(): Convierte una coordenada X en un valor RGB.

mlx_y_to_rgb(): Convierte una coordenada Y en un valor RGB.

mlx_wait_key(): Espera a que se pulse una tecla.

mlx_loop(): Entra en un bucle de eventos.

mlx_destroy_window(): Destruye una ventana.

mlx_destroy_display(): Destruye una pantalla.