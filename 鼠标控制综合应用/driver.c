 input_report_rel(amimouse_dev, REL_X, dx);
    input_report_rel(amimouse_dev, REL_Y, dy);

    input_report_key(amimouse_dev, BTN_LEFT, ciaa.pra & 0x40);
    input_report_key(amimouse_dev, BTN_MIDDLE, potgor & 0x0100);
    input_report_key(amimouse_dev, BTN_RIGHT, potgor & 0x0400);

    input_sync(amimouse_dev);//