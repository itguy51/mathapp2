#include "pebble.h"
#include "trig_limits.h"
	
#define NUM_TRIG_LIMITS_MENU_ITEMS 2

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem trig_limits_menu_items[NUM_TRIG_LIMITS_MENU_ITEMS];

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {
  int num_a_items = 0;

  trig_limits_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "lim[x->0]",
	.subtitle = "sin(x)/x = 1",
  };
  trig_limits_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "lim[x->0] ",
	.subtitle = "(1-cos(x))/x = 0",
  };
  menu_sections.num_items = NUM_TRIG_LIMITS_MENU_ITEMS;
  menu_sections.items = trig_limits_menu_items;

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

void show_trig_limits_menu(){
   window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}