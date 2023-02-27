#include "user_actions.h"
#include "logic.h"

#define ENTER_ASCII_VALUE 13
#define SMALLEST_UPPER_CASE_ASCII_VALUE 65
#define HIGHEST_UPPER_CASE_ASCII_VALUE 90
#define SMALLEST_LOWER_CASE_ASCII_VALUE 97
#define HIGHEST_LOWER_CASE_ASCII_VALUE 122

const char *HANGMAN_ASCII_ART[] =
    {
        " ",
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                                      MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM",

        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                                      MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM",

        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                              MMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                                      MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM",

        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                              MMMMMMMMMMM\n\r"
        "MMM    MMMMM   MMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMM   MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    M  MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM     MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                                      MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM",

        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                              MMMMMMMMMMM\n\r"
        "MMM    MMMMM   MMMMMMMMMMMMM MMMMMMMMMMMMMMM\n\r"
        "MMM    MMM   MMMMMMMMMMMMMMM MMMMMMMMMMMMMMM\n\r"
        "MMM    M  MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM     MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                                      MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM",

        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                              MMMMMMMMMMM\n\r"
        "MMM    MMMMM   MMMMMMMMMMMMM MMMMMMMMMMMMMMM\n\r"
        "MMM    MMM   MMMMMMMMMMMMMMM MMMMMMMMMMMMMMM\n\r"
        "MMM    M  MMMMMMMMMMMMMMMMM    MMMMMMMMMMMMM\n\r"
        "MMM     MMMMMMMMMMMMMMMMMM      MMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMM    MMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                                      MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM",

        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                              MMMMMMMMMMM\n\r"
        "MMM    MMMMM   MMMMMMMMMMMMM MMMMMMMMMMMMMMM\n\r"
        "MMM    MMM   MMMMMMMMMMMMMMM MMMMMMMMMMMMMMM\n\r"
        "MMM    M  MMMMMMMMMMMMMMMMM    MMMMMMMMMMMMM\n\r"
        "MMM     MMMMMMMMMMMMMMMMMM      MMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMM    MMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMM         MMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMM      MMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMM      MMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMM      MMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                                      MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM",

        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                              MMMMMMMMMMM\n\r"
        "MMM    MMMMM   MMMMMMMMMMMMM MMMMMMMMMMMMMMM\n\r"
        "MMM    MMM   MMMMMMMMMMMMMMM MMMMMMMMMMMMMMM\n\r"
        "MMM    M  MMMMMMMMMMMMMMMMM    MMMMMMMMMMMMM\n\r"
        "MMM     MMMMMMMMMMMMMMMMMM      MMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMM    MMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMM          MMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMM   M      MMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMM  MM      MMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMM MMM      MMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                                      MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM",

        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                              MMMMMMMMMMM\n\r"
        "MMM    MMMMM   MMMMMMMMMMMMM MMMMMMMMMMMMMMM\n\r"
        "MMM    MMM   MMMMMMMMMMMMMMM MMMMMMMMMMMMMMM\n\r"
        "MMM    M  MMMMMMMMMMMMMMMMM    MMMMMMMMMMMMM\n\r"
        "MMM     MMMMMMMMMMMMMMMMMM      MMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMM    MMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMM          MMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMM   M      M   MMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMM  MM      MM  MMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMM MMM      MMM MMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                                      MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM",

        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                              MMMMMMMMMMM\n\r"
        "MMM    MMMMM   MMMMMMMMMMMMM MMMMMMMMMMMMMMM\n\r"
        "MMM    MMM   MMMMMMMMMMMMMMM MMMMMMMMMMMMMMM\n\r"
        "MMM    M  MMMMMMMMMMMMMMMMM    MMMMMMMMMMMMM\n\r"
        "MMM     MMMMMMMMMMMMMMMMMM      MMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMM    MMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMM          MMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMM   M      M   MMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMM  MM      MM  MMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMM MMM      MMM MMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMM   MMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMM   MMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMM   MMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMM   MMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                                      MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM",

        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                              MMMMMMMMMMM\n\r"
        "MMM    MMMMM   MMMMMMMMMMMMM MMMMMMMMMMMMMMM\n\r"
        "MMM    MMM   MMMMMMMMMMMMMMM MMMMMMMMMMMMMMM\n\r"
        "MMM    M  MMMMMMMMMMMMMMMMM    MMMMMMMMMMMMM\n\r"
        "MMM     MMMMMMMMMMMMMMMMMM      MMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMM    MMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMM          MMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMM   M      M   MMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMM  MM      MM  MMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMM MMM      MMM MMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMM   M   MMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMM   MMM   MMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMM   MMM   MMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMM   MMM   MMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                                      MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"};

const char *starting_screen[] =
    {
        "\n\r"
        "  _   _                   __  __              \n\r"
        " | | | | __ _ _ __   __ _|  \\/  | __ _ _ __   \n\r"
        " | |_| |/ _` | '_ \\ / _` | |\\/| |/ _` | '_ \\  \n\r"
        " |  _  | (_| | | | | (_| | |  | | (_| | | | | \n\r"
        " |_| |_|\\__,_|_| |_|\\__, |_|  |_|\\__,_|_| |_| \n\r"
        "                    |___/ Terminal Edition    \n\r"
        "_____________________________________________ \n\r"
        "     _     __________________ \n\r"
        "   _|_|_  |                  |\n\r"
        "    ( )  <  Wanna hang out?  |\n\r"
        "    /|\\   |__________________|\n\r"
        "     |\n\r"
        "    / \\  \n\r"};

const char *game_over_ascii_art[] =
    {
        "\n\r"
        "   ____                         ___                 \n\r"
        "  / ___| __ _ _ __ ___   ___   / _ \\__   _____ _ __ \n\r"
        " | |  _ / _` | '_ ` _ \\ / _ \\ | | | \\ \\ / / _ | '__|\n\r"
        " | |_| | (_| | | | | | |  __/ | |_| |\\ V |  __| |   \n\r"
        "  \\____|\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|   \n\r"
        "\n\r"
        "     _     __________________________\n\r"
        "   _|_|_  |                          |\n\r"
        "    ( )  <  You ain't got the hang!  |\n\r"
        "    \\|/   | F§%$ You D&%§&$§$%!!!!|\n\r"
        "     |    |__________________________|\n\r"
        "    / \\                               \n\r"};

const char *win_ascii_art[] =
    {
        "                                                 _     ____________________ \n\r"
        " __   __                       _         _     _|_|_  |                    |\n\r"
        " \\ \\ / ___  _   _    __      _(_)_ __   | |     ( )  <  We did it! Cheers! |\n\r"
        "  \\ V / _ \\| | | |   \\ \\ /\\ / | | '_ \\  | |     \\|/   |____________________|\n\r"
        "   | | (_) | |_| |    \\ V  V /| | | | | |_|      |                          \n\r"
        "   |_|\\___/ \\__,_|     \\_/\\_/ |_|_| |_| (_)     / \\                         \n\r"};

const char *stats[] =
    {
        "____________________________________________________\n\r"
        "STATS\n\r"
        "____________________________________________________"
        "\n\r"
        "NO. OF TRIES: ",
        "placeholder\n\r",
        "\n\rNO. OF MISENTRIES: ",
        "placeholder\n\r",
        "\n\r"
        "NO. OF TIMEOUTS: ",
        "placeholder\n\r",
        "____________________________________________________\n\r"
        "\n\r"};

const char *play_again_ascii_art[] =
    {
        "      __    _____                                _          __       \n\r"
        "      \\ \\  |_   __ __ _   _     __ _  __ _  __ _(_)_ __    / /       \n\r"
        "  =====\\ \\   | || '__| | | |   / _` |/ _` |/ _` | | '_ \\  / /=====   \n\r"
        "  =====/ /   | || |  | |_| |  | (_| | (_| | (_| | | | | | \\ \\=====   \n\r"
        "      /_/    |_||_|   \\__, |   \\__,_|\\__, |\\__,_|_|_| |_|  \\_\\       \n\r"
        "                      |___/          |___/                           \n\r"};

const char *end_game_ascii_art[] =
    {
        " ______           _           _     __________________\n\r"
        "|  ____|         | |        _|_|_  |                  |\n\r"
        "| |__   _ __   __| |         ( )  <      Cheerio!     |\n\r"
        "|  __| | '_ \\ / _` |         \\|/   |__________________|\n\r"
        "| |____| | | | (_| |          |\n\r"
        "|______|_| |_|\\__,_|         / \\  \n\r\n\r"

        "__Credits__\n\r"
        "\n\r"
        "Chief Executive Backend Master and Supervision     Janik\n\r"
        "Principal Pixelschubse and Location Scout          Pascal\n\r"
        "Head of Bugsniffing and Casting Director           Caro\n\r\n\r"

        "__Special Thanks To__\n\r"
        "\n\r"
        "Shout out for the project idea                     Sven & Thomas\n\r"
        "Stunts & Master of Communication                   Hans a.k.a. The Hangman\n\r"};

const char *rules_ascii_art[] =
    {
        "            _______________________________________\n\r"
        "           |                                       |\n\r"
        "           | Here are the rules for your word:     |\n\r"
        "           | 1) use any letter from a-z or A-Z     |\n\r"
        "           | 2) max. length of 25 letters          |\n\r"
        "           | 3) type an umlaut as ue, oe, ae       |\n\r"
        "           | 4) no special characters or numbers   |\n\r"
        "     _     | 5) no words with hyphens or spaces    |\n\r"
        "   _|_|_   |                                       |\n\r"
        "    ( )   <  Always remember: Don't let me hang!   |\n\r"
        "    \\|/    |_______________________________________|\n\r"
        "     | \n\r"
        "    / \\  \n\r\n\r"
        "Think wisely, type in your word and confirm with Enter:\n\r"};

/**
 * @brief draw hangman at the given position to the console
 *
 * @param incorrect
 */
void draw_hangman(int incorrect)
{
    print_word(HANGMAN_ASCII_ART[incorrect]);
}

/**
 * @brief fills the stats array with the given array at the given position
 * @details position = 1 => over all tries; position = 3 => misentries, function checks if position has one of these two values
 * @param array_with_number
 * @param position
 */
void fill_stats(const char *array_with_number, int position)
{
    if (position == 1 || position == 3 || position == 5)
    {
        stats[position] = array_with_number;
    }
}

/**
 * @brief draws play again ascii art to the console
 */
void draw_play_again(void)
{
    print_word(play_again_ascii_art[0]);
}

/**
 * @brief draws game over ascii art to the console
 */
void draw_game_over()
{
    print_word(game_over_ascii_art[0]);
}

/**
 * @brief draws statistics to the console
 */
void draw_stats()
{
    for (int i = 0; i < (sizeof(stats) / sizeof(stats[0])); i++)
    {
        print_word(stats[i]);
    }
}

/**
 * @brief draws you win ascii art to the console
 */
void draw_you_win()
{
    print_word(win_ascii_art[0]);
}

/**
 * @brief draws you win ascci art to the console
 */
void draw_end()
{
    print_word(end_game_ascii_art[0]);
}

/**
 * @brief draws starting screen ascii art to the console
 */
void draw_starting_screen()
{
    print_word(starting_screen[0]);
}

/**
 * @brief draws rules ascii art to the console
 */
void draw_rules()
{
    print_word(rules_ascii_art[0]);
}

/**
 * @brief Get the word to guess
 * @details this function returns the size of the word, because the array is initialized empty with a fixed size, so the sizeof function would return always the same value for this array
 * @param word_to_guess array which gets filled by this function
 * @return int length of the given word
 */
int get_word_to_guess(char *word_to_guess, int size)
{
    int position = 0;
    while (position < size)
    {
        char input = read();
        int input_ascii_value = input;
        if (input_ascii_value >= SMALLEST_UPPER_CASE_ASCII_VALUE && input_ascii_value <= HIGHEST_UPPER_CASE_ASCII_VALUE)
        {
            word_to_guess[position] = input;
            position += 1;
        }
        else if (input_ascii_value >= SMALLEST_LOWER_CASE_ASCII_VALUE && input_ascii_value <= HIGHEST_LOWER_CASE_ASCII_VALUE)
        {
            word_to_guess[position] = toUpper(input);
            position += 1;
        }
        else if (input_ascii_value == ENTER_ASCII_VALUE)
        {
            return position;
        }
    }
    return position;
}

/**
 * @brief wait for user input in order to continue the game
 *
 */
void waitForAnyInput()
{
    while (1)
    {
        char input = read();
        return;
    }
}

/**
 * @brief clears the console
 *
 */
void clear_screen()
{
    print_word("\033[H\033[J");
}

/**
 * @brief prints single charcter to console by using printChar function
 *
 * @param text
 */
void print_single_character(char text)
{
    printChar(text);
}

/**
 * @brief reads input from console and returns it
 *
 * @return char
 */
char read()
{
    char input = read_input();
    return input;
}

/**
 * @brief calls function read_input_with_interrupt_handling in hal.c
 *
 * @return char
 */
char read_with_interrupt_handling(void)
{
    char input = read_input_with_interrupt_handling();
    return input;
}

/**
 * @brief prints 'String' to the console by using the printString function
 *
 * @param text
 */
void print_word(const char *text)
{
    printString(text);
}
