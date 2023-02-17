// Obins stock firmware has something similar to this already enabled, but disabled by default in QMK
#define PERMISSIVE_HOLD

#define _INDICATOR_COLOR RGB_GREEN
#define _LAYER_1_COLOR   RGB_PURPLE
#define _LAYER_2_COLOR   RGB_BLUE

#define LED_TAB 28

// set delay to 200ms for key hold
#define TAPPING_TERM 200

// Enable all the effects
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES

// Enable CAPSWORD with both shifts
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// Set a timeout to complete a leader sequence
#define LEADER_TIMEOUT 400

// quit vim mode with :q
#define VIM_COLON_CMDS
#define VIM_FOR_ALL
#define BETTER_VISUAL_MODE
