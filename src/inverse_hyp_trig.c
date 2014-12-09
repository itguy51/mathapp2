#include "pebble.h"
#include "inverse_hyp_trig.h"
	
#define NUM_INVERSE_HYP_TRIG_MENU_ITEMS 6

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem inverse_hyp_trig_menu_items[NUM_INVERSE_HYP_TRIG_MENU_ITEMS];

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {
  int num_a_items = 0;

  inverse_hyp_trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "arcsinh'(x)",
	.subtitle = "1/(x²+1)^½",
  };
  inverse_hyp_trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "arccosh'(x)",
	.subtitle = "1/(x²-1)^½",
  };
  inverse_hyp_trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "arctanh'(x)",
	.subtitle = "1/(1-x²)",
  };
  inverse_hyp_trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "arcsech'(x)",
  .subtitle = "-1/x(1-x²)^½",
  };
  inverse_hyp_trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "arccoth'(x)",
  .subtitle = "1/(1-x²)",
  };
  inverse_hyp_trig_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "arccsch'(x)",
  .subtitle = "-1/|x|(1+x²)^½",
  };

  menu_sections.num_items = NUM_INVERSE_HYP_TRIG_MENU_ITEMS;
  menu_sections.items = inverse_hyp_trig_menu_items;

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

void show_inverse_hyp_trig_menu(){
   window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}