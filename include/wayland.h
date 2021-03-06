#ifndef WAYLAND_H
#define WAYLAND_H

#include <cairo/cairo.h>
#include <wayland-client.h>
#include <wayland-cursor.h>
#include "wlr-layer-shell-unstable-v1.h"

struct wayland_state {
	//Display
	struct wl_display *display;
	struct wl_registry *registry;
	struct wl_compositor *compositor;
	struct wl_shm *shm;
	struct wl_shm_pool *pool;
	struct wl_buffer *buffer;
	struct zwlr_layer_shell_v1 *layer_shell;
	struct zwlr_layer_surface_v1 *layer_surface;
	struct wl_output *wl_output;
	struct wl_surface *wl_surface;

	//Cairo and pixman
	cairo_surface_t *cairo_surface;
	cairo_t *cairo;
	
	//Input
	struct wl_seat *seat;
	struct wl_pointer *pointer;
	struct wl_cursor_image *cursor_image;
	struct wl_cursor_theme *cursor_theme;
	struct wl_surface *cursor_surface, *input_surface;
};

int init_wayland(int argc, char *argv[]);
int free_wayland(void);
int draw(void);

#endif
