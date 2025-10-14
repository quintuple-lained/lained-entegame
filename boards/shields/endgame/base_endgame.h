#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/outputs.h>
#include "keys_de.h"

#define APT 0
#define NUM 1
#define NAV 2
#define SYM 3
#define DE 4

#define QUICK_TAP_TIME 200

// &lt {
//     quick_tap_ms = <170>;
// };

// space invader key numbers
//  ____________________________________________________________
// /  0  |  1  |  2  |  3  |  4       5 |   6 |   7 |   8 |  9  \
// | 10  | 11  | 12  | 13  | 14      15 |  16 |  17 |  18 | 19  |
// | 20  | 21  | 22  | 23  | 24      25 |  26 |  27 |  28 | 29  |
// \ 30  |             31    32      33 |  34             | 35  /
//           --------------              --------------

&caps_word {
    continue-list = <UNDERSCORE MINUS BSPC LSHFT RSHFT>;
};


/ {
  macros {
  macro_sch:
    macro_sch {
      label = "Macro_sch";
      compatible = "zmk,behavior-macro";
      #binding-cells = <0>;
      bindings = <&macro_tap &kp S &macro_release &kp RSHIFT &macro_tap &kp C &kp H>;
    };
  };
};

#define COMBO(NAME, BINDINGS, KEYPOS) \
  combo_##NAME {                      \
    timeout-ms = <20>;                \
    bindings = <BINDINGS>;            \
    key-positions = <KEYPOS>;         \
  };

/ {
    combos {
        compatible = "zmk,combos";
/* usually on base layer */
        COMBO(q, &kp Q, 2 3)
        COMBO(z, &kp DE_Z, 21 22)
        COMBO(v, &kp V, 1 2)
        COMBO(b, &kp B, 12 3)
        COMBO(k, &kp K, 12 13)
        COMBO(x, &kp X, 16 17)
        COMBO(j, &kp J, 6 17)
        COMBO(sch, &macro_sch, 11 13)
        COMBO(_sz, &kp DE_SZ, 33 11)
        COMBO(_ue, &kp DE_UE, 33 8)
        COMBO(_ae, &kp DE_AE, 33 17)
        COMBO(_oe, &kp DE_OE, 33 19)
        COMBO(ent, &kp ENTER, 26 27)
        COMBO(esc, &kp ESC, 23 24)
/* caps */
        COMBO(capsword, &caps_word, 13 16)
        COMBO(capslock, &kp CAPSLOCK, 0 9)
/* deletion */
        COMBO(bspc, &kp BSPC, 6 7)
        COMBO(del, &kp DEL, 7 8)
        COMBO(bspcword, &kp LC(BSPC), 6 8)

    };
};


/ {

    behaviors {
        hl: homerow_mods_left {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods left";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <QUICK_TAP_TIME>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <5 6 7 8 9 15 16 17 18 19 25 26 27 28 29 33 34 35>;
        };
        hr: homerow_mods_right {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods right";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <QUICK_TAP_TIME>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <0 1 2 3 4 10 11 12 13 14 20 21 22 23 24 30 31 32>;
        };

        my_lt: my_layer_taps {
            compatible = "zmk,behavior-hold-tap";
            label = "my layer taps";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <QUICK_TAP_TIME>;
            // global-quick-tap;
            bindings = <&mo &kp>, <&kp>;
            // non-thumb keys
            hold-trigger-key-positions = <0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35>;
        };

        dotcol: dot_colon {
            compatible = "zmk,behavior-mod-morph";
            label = "DOT_COL";
            #binding-cells = <0>;
            bindings = <&kp DOT>, <&kp COLON>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
        comsem: comma_semicolon {
            compatible = "zmk,behavior-mod-morph";
            label = "COM_SEM";
            #binding-cells = <0>;
            bindings = <&kp COMMA>, <&kp SEMI>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
    };
};
