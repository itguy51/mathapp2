#include "pebble.h"
#include "hyp_trig.h"
	
#define NUM_HYP_TRIG_MENU_ITEMS 9

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem hyp_trig_menu_items[NUM_HYP_TRIG_MENU_ITEMS];

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {
  int num_a_items = 0;

  hyp_trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "sinh(x)",
	.subtitle = "(e^x - e^-x)/2",
  };
  hyp_trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "cosh(x)",
	.subtitle = "(e^x + e^-x)/2",
  };
  hyp_trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "tanh(x)",
	.subtitle = "(e^x - e^-x)/(e^x + e^-x)",
  };
  hyp_trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "sinh'(x)",
  .subtitle = "cosh(x)",
  };
  hyp_trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "tanh'(x)",
  .subtitle = "sech²(x)",
  };
  hyp_trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "sech'(x)",
  .subtitle = "-sech(x)tanh(x)",
  };
  hyp_trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "cosh'(x)",
  .subtitle = "sinh(x)",
  };
  hyp_trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "coth'(x)",
  .subtitle = "-csc²(x)",
  };
  hyp_trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "csch'(x)",
  .subtitle = "-csch(x)coth(x)",
  };

  menu_sections.num_items = NUM_HYP_TRIG_MENU_ITEMS;
  menu_sections.items = hyp_trig_menu_items;

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

void show_hyp_trig_menu(){
   window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}