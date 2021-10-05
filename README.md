# EtherCatTest1
This is an example code for using IgH EtherCat master. It is based on the example code provided from the IgH EtherCat, but uses different slaves, EasyCAT. Also detailed comments have been added to help one's understanding

## Basic procedure for running EtherCat master.
1. Request master 
    : Obtain a handle to the EtherCAT master managed by EtherCAT kernel module.
    ```
    // 'ecrt_request_master(index)'. Returns pointer to 'ec_master_t' 
    master = ecrt_request_master(0);
    ```

2. Create a Process Data Domain
   : Image of the process data objects (PDO) that will be exchanged through EtherCAT communication are managed by 'Process Data Domain'. 
   ```
    // 'ecrt_master_create_domain(ec_master_t*)'. Returns pointer to ec_domain_t
    domain1 = ecrt_master_create_domain(master);
   ```

3. Configure slaves
   : Provide master with the information about the connected slaves (alias, position, vendor id, product code).
    ```
    // ecrt_master_slave_config(master, alias, position, vendor_id, product code)
    sc1 = ecrt_master_slave_config(master,0,0,VendorID_EasyCAT,ProductCode_LAB1)
    ```
    
4. For each slaves, configure 'sync manager'
   : Sync manager coordinates the synchronization of data exchange through Process Data Objects (PDO)
    ```
    // PDO mapping consists of 
    // 1. 'ec_pdo_entry_info_t' which specifies index/subindex/size of an object that will be mapped to PDO
    // 2. 'ec_pdo_info_t' which specifies index in a slave's object dictionary (PDO index) that the entry information will be stored. 
    // 3. 'ec_sync_info_t', sync manager configuration information
    ecrt_slave_config_pdos (slave configuration, number of sync manager, array of ec_sync_info_t)
    ```

5. Registers a PDO entry for process data exchange in a domain. PDO configuration (sync manager configuration) of each slave is registered to Process Data Domain and obtain 'offset' of each object, which will be used later for reading and writing is returned. 
    // offset = ecrt_slave_config_reg_pdo_entry(slave configuration, index, subindex, domain)
    ```
6. Configure SYNC signal 
7. Activate master, obtain pointer to process data domain's memory
   ``` 
   ecrt_master_activate(master);
   domain1_pd = ecrt_domain_data(domain1);
   ```

8. Start cyclic data exchange. Exchange process data consists of
 - Receive and process data
   ```
   ecrt_master_receive(master);
   ecrt_domain_process(domain1);
   ```
 - Update new data to write 
 - Read and write process data using macros EC_READ_XXX, EC_WRITE_XXX. Offset for each PDO object is used here. 
   ```
   EC_READ_REAL(domain1_pd + offsetTemperature);
   EC_WRITE_U8(domain1_pd + offsetAlarm, 127);
   ```
 - Queue and send process data
   ```
   ecrt_domain_queue(domain1);
   ecrt_master_send(master);
   ```
