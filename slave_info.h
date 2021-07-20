 /* Master 0, Slave 0, "LAB_1"
 * Vendor ID:       0x0000079a
 * Product code:    0xababa001
 * Revision number: 0x00000001
 */

ec_pdo_entry_info_t slave_0_pdo_entries[] = {
    {0x0005, 0x01, 8}, /* Alarm */
    {0x0006, 0x01, 32}, /* Temperature */
};

ec_pdo_info_t slave_0_pdos[] = {
    {0x1600, 1, slave_0_pdo_entries + 0}, /* Outputs */
    {0x1a00, 1, slave_0_pdo_entries + 1}, /* Inputs */
};

ec_sync_info_t slave_0_syncs[] = {
    {0, EC_DIR_OUTPUT, 1, slave_0_pdos + 0, EC_WD_ENABLE},
    {1, EC_DIR_INPUT, 1, slave_0_pdos + 1, EC_WD_DISABLE},
    {0xff}
};

/* Master 0, Slave 1, "LAB_2"
 * Vendor ID:       0x0000079a
 * Product code:    0xababa002
 * Revision number: 0x00000001
 */

ec_pdo_entry_info_t slave_1_pdo_entries[] = {
    {0x0005, 0x01, 8}, /* Segments */
    {0x0006, 0x01, 16}, /* Potentiometer */
    {0x0006, 0x02, 8}, /* Switches */
};

ec_pdo_info_t slave_1_pdos[] = {
    {0x1600, 1, slave_1_pdo_entries + 0}, /* Outputs */
    {0x1a00, 2, slave_1_pdo_entries + 1}, /* Inputs */
};

ec_sync_info_t slave_1_syncs[] = {
    {0, EC_DIR_OUTPUT, 1, slave_1_pdos + 0, EC_WD_ENABLE},
    {1, EC_DIR_INPUT, 1, slave_1_pdos + 1, EC_WD_DISABLE},
    {0xff}
};

