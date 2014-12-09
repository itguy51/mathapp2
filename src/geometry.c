#include "pebble.h"
#include "geometry.h"

	
#define NUM_GEOMETRY_MENU_ITEMS 4

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem geometry_menu_items[NUM_GEOMETRY_MENU_ITEMS];

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {
  int num_a_items = 0;

  geometry_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Pythagorean Theorem",
	.subtitle = "A²+B²=C²"
  };
  geometry_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Area of a Circle",
	.subtitle = "pi*r²"
  };
  geometry_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Area of a Triangle",
	.subtitle = "1/2*B*H"
  };
  geometry_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Cone Volume",
	.subtitle = "(1/3)b*h = 1/3*pi*r²*h"
  };
  menu_sections.num_items = NUM_GEOMETRY_MENU_ITEMS;
  menu_sections.items = geometry_menu_items;

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

void show_geometry_menu(){
   window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}