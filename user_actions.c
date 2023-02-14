#include "user_actions.h"

#include <stdio.h>

const char *HANGMAN_ASCII_ART[] = {
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
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r",

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
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r",

        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
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
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                                      MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r",

        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
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
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                                      MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r",

        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                              MMMMMMMMMMM\n\r"
        "MMM    MMMMM   MMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMM   MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    M   MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM       MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
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
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                                      MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r",

        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                              MMMMMMMMMMM\n\r"
        "MMM    MMMMM   MMMMMMMMMMMMMMM MMMMMMMMMMMMM\n\r"
        "MMM    MMM   MMMMMMMMMMMMMMMMM MMMMMMMMMMMMM\n\r"
        "MMM    M   MMMMMMMMMMMMMMMMMMM MMMMMMMMMMMMM\n\r"
        "MMM       MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
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
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                                      MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r",

        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                              MMMMMMMMMMM\n\r"
        "MMM    MMMMM   MMMMMMMMMMMMMMM MMMMMMMMMMMMM\n\r"
        "MMM    MMM   MMMMMMMMMMMMMMMMM MMMMMMMMMMMMM\n\r"
        "MMM    M   MMMMMMMMMMMMMMMMMMM MMMMMMMMMMMMM\n\r"
        "MMM       MMMMMMMMMMMMMMMMMMM    MMMMMMMMMMM\n\r"
        "MMM     MMMMMMMMMMMMMMMMMMMM      MMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMM    MMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMM  MMMMMMMMMMMM\n\r"
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
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r",

        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                              MMMMMMMMMMM\n\r"
        "MMM    MMMMM   MMMMMMMMMMMMMMM MMMMMMMMMMMMM\n\r"
        "MMM    MMM   MMMMMMMMMMMMMMMMM MMMMMMMMMMMMM\n\r"
        "MMM    M   MMMMMMMMMMMMMMMMMMM MMMMMMMMMMMMM\n\r"
        "MMM       MMMMMMMMMMMMMMMMMMM    MMMMMMMMMMM\n\r"
        "MMM     MMMMMMMMMMMMMMMMMMMM      MMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMM    MMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMM  MMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMM      MMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMM       MMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMM       MMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMM       MMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMM       MMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMM       MMMMMMMMMM\n\r"
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
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r",

        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                              MMMMMMMMMMM\n\r"
        "MMM    MMMMM   MMMMMMMMMMMMMMM MMMMMMMMMMMMM\n\r"
        "MMM    MMM   MMMMMMMMMMMMMMMMM MMMMMMMMMMMMM\n\r"
        "MMM    M   MMMMMMMMMMMMMMMMMMM MMMMMMMMMMMMM\n\r"
        "MMM       MMMMMMMMMMMMMMMMMMM    MMMMMMMMMMM\n\r"
        "MMM     MMMMMMMMMMMMMMMMMMMM      MMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMM    MMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMM  MMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMM      MMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMM          MMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMM       M   MMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMM       MM  MMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMM       MM  MMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMM       MMMMMMMMMM\n\r"
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
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r",

        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                              MMMMMMMMMMM\n\r"
        "MMM    MMMMM   MMMMMMMMMMMMMMM MMMMMMMMMMMMM\n\r"
        "MMM    MMM   MMMMMMMMMMMMMMMMM MMMMMMMMMMMMM\n\r"
        "MMM    M   MMMMMMMMMMMMMMMMMMM MMMMMMMMMMMMM\n\r"
        "MMM       MMMMMMMMMMMMMMMMMMM    MMMMMMMMMMM\n\r"
        "MMM     MMMMMMMMMMMMMMMMMMMM      MMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMM    MMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMM  MMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMM      MMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMM            MMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMM   M       M   MMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMM  MM       MM  MMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMM  MM       MM  MMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMM       MMMMMMMMMM\n\r"
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
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r",

        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                              MMMMMMMMMMM\n\r"
        "MMM    MMMMM   MMMMMMMMMMMMMMM MMMMMMMMMMMMM\n\r"
        "MMM    MMM   MMMMMMMMMMMMMMMMM MMMMMMMMMMMMM\n\r"
        "MMM    M   MMMMMMMMMMMMMMMMMMM MMMMMMMMMMMMM\n\r"
        "MMM       MMMMMMMMMMMMMMMMMMM    MMMMMMMMMMM\n\r"
        "MMM     MMMMMMMMMMMMMMMMMMMM      MMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMM    MMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMM  MMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMM      MMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMM            MMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMM   M       M   MMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMM  MM       MM  MMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMM  MM       MM  MMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMM       MMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMM    MMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMM   MMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMM   MMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMM   MMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMM   MMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r"
        "MMM                                      MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMM\n\r"
        "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\r",
};



/// @brief draws hangman picture
/// @param incorrect 
void draw_hangman(int incorrect) {
    print_word(HANGMAN_ASCII_ART[incorrect]);

}

void print_single_character(char text)
{
    printChar(text);
}

char read(void)
{
    char input = read_input();
    return input;
}

void print_word(const char* text) 
{
    printString(text);
}