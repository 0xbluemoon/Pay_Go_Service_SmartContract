# Pay_Go_Service_SmartContract
Keep vendor information in EOS smart contract

The smart contract is compiled by EOS CDT 1.3

You may need to update the folder name to income_14.


```
cd folder
mkdir build
cd build
cname ..
make
```

deploy smart contract
```
cleos -u https://nodes.get-scatter.com set contract  youreosaccount income_14 --permission youreosaccount@active
```
create record
```
cleos  -u https://nodes.get-scatter.com push action youreosaccount create '{"setup_time":1, "service_info":"dead beef duck"}' --permission youreosaccount@active
```
list record
```
cleos -u  https://nodes.get-scatter.com get table youreosaccount youreosaccount srvportal
```
remove record
```
cleos  -u https://nodes.get-scatter.com push action youreosaccount remove '{"setup_time":1}' --permission youreosaccount@active
```
list again
```
cleos -u  https://nodes.get-scatter.com get table youreosaccount youreosaccount srvportal
```
