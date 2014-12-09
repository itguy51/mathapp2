#include "pebble.h"
#include "algebra.h"
#include "geometry.h"
#include "trigonometry.h"
#include "calc.h"
//My Stuff.
#include "trig_deriv.h"
#include "inverse_trig_deriv.h"
#include "hyp_trig.h"
#include "inverse_hyp_trig.h"
#include "trig_limits.h"

#define NUM_MATH_MENU_ITEMS 4
#define NUM_MENU_SECTIONS 2
#define NUM_TRIG_CALC_MENU_ITEMS 5

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections[NUM_MENU_SECTIONS];

static SimpleMenuItem math_menu_items[NUM_MATH_MENU_ITEMS];
static SimpleMenuItem trig_calc_menu_items[NUM_TRIG_CALC_MENU_ITEMS];
//Callbacks

static void algebra_select_callback(int index, void *ctx) {
  show_algebra_menu();
}
static void geometry_select_callback(int index, void *ctx) {
  show_geometry_menu();
}
static void trig_select_callback(int index, void *ctx) {
  show_trig_menu();
}
static void calc_select_callback(int index, void *ctx) {
  show_calc_menu();
}
static void trig_deriv_select_callback(int index, void *ctx) {
  show_trig_deriv_menu();
}
static void inverse_trig_deriv_select_callback(int index, void *ctx) {
  show_inverse_trig_deriv_menu();
}
static void hyp_trig_select_callback(int index, void *ctx) {
  show_hyp_trig_menu();
}
static void inverse_hyp_trig_select_callback(int index, void *ctx) {
  show_inverse_hyp_trig_menu();
}
static void trig_limits_select_callback(int index, void *ctx) {
  show_trig_limits_menu();
}

static void window_load(Window *window) {

  int num_a_items = 0;
  int num_a2_items = 0;
  int num_a3_items = 0;
  int num_a4_items = 0;

  math_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Algebra",
	.subtitle = "Algebraic Formulas",
    .callback = algebra_select_callback,
  };
  math_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Geometry",
	.subtitle = "Geometric Formulas",
    .callback = geometry_select_callback,
  };
  math_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Trigonometry",
	.subtitle = "Trig Formulas",
    .callback = trig_select_callback,
  };
  math_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Calculus",
	.subtitle = "Calc Formulas",
    .callback = calc_select_callback,
  };
  //TC BEGIN
  trig_calc_menu_items[num_a2_items++] = (SimpleMenuItem){
    .title = "Trig",
	.subtitle = "Normal Trig",
    .callback = trig_deriv_select_callback,
  };
  trig_calc_menu_items[num_a2_items++] = (SimpleMenuItem){
    .title = "Inverse Trig",
  .subtitle = "Inverse Trig",
    .callback = inverse_trig_deriv_select_callback,
  };
  trig_calc_menu_items[num_a2_items++] = (SimpleMenuItem){
    .title = "Hyp. Trig",
  .subtitle = "Hyperbolic Trig",
    .callback = hyp_trig_select_callback,
  };
  trig_calc_menu_items[num_a2_items++] = (SimpleMenuItem){
    .title = "Inv. Hyp. Trig",
  .subtitle = "Inverse Hyp. Trig",
    .callback = inverse_hyp_trig_select_callback,
  };
  trig_calc_menu_items[num_a2_items++] = (SimpleMenuItem){
    .title = "Trig Limits",
  .subtitle = "Limits!",
    .callback = trig_limits_select_callback,
  };
  //TC END
  menu_sections[0] = (SimpleMenuSection){
  .title ="Math Formulas",
  .num_items = NUM_MATH_MENU_ITEMS,
  .items = math_menu_items,
  };
  menu_sections[1] = (SimpleMenuSection){
  .title ="Trig Calc Formulas",
  .num_items = NUM_TRIG_CALC_MENU_ITEMS,
  .items = trig_calc_menu_items,
  };
	
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, menu_sections,NUM_MENU_SECTIONS, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
}

int main(void) {
  window = window_create();


  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });

  window_stack_push(window, true /* Animated */);

  app_event_loop();

  window_destroy(window);
}
/* This app is created by Devin Simmons, anyone can feel free to use this code to make their own apps as long as you
give credit!!

Thanks for using the app! Please leave a review, and if you would like any formulas or equations added contact me at blackpaw1996@gmail.com,
or on Google Plus!

A big thanks to Grégoire Sage for helping guide me through learning how to code!

*/
