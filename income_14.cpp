#include <eosiolib/eosio.hpp>

using namespace eosio;

/* you can use this method of declaration */
//class [[eosio::contract]] multi_index_example : public contract {
/* or this method of declaration if you don't want to use the c++ class name */
//class [[eosio::contract("<some contract name>")]] multi_index_example : public contract {
CONTRACT income_14: public contract {
  public:
      using contract::contract;
      income_14( name receiver, name code, datastream<const char*> ds )
         : contract(receiver, code, ds), srvportals(receiver, receiver.value) {}

//      [[eosio::action]]
//      void create(const uint64_t& setup_time,  const string& service_info){
      ACTION create(const uint64_t& setup_time,  const std::string& service_info){
         require_auth(_self);
		   auto iterSP = srvportals.find(setup_time);
		   if (iterSP == srvportals.end()){
			   srvportals.emplace(_self, [&](auto& row) {
				   row.setup_time= setup_time;
				   row.service_info = service_info;
				});
		   }else{
			   srvportals.modify(iterSP,_self, [&](auto& row) {
				   row.service_info = service_info;
			   });
		   }
	   }
//      [[eosio::action]]
//      void remove(const uint64_t& setup_time){
      ACTION remove(const uint64_t& setup_time){
         require_auth(_self);
		   auto iterSP = srvportals.find(setup_time);
		      if (iterSP == srvportals.end()){
		   }else{
			   srvportals.erase(iterSP);
		   }
	   }

//      struct [[eosio::table]] test_table {
      TABLE srvportal {
			uint64_t setup_time;
			std::string service_info;
			uint64_t primary_key()const { return setup_time; }
      };


      typedef eosio::multi_index<"srvportal"_n, srvportal> srvpsrvportal_table;

      using create_action   = action_wrapper<"create"_n, &income_14::create>;
      using remove_action   = action_wrapper<"remove"_n, &income_14::remove>;
  private:
      srvpsrvportal_table srvportals;
};

EOSIO_DISPATCH( income_14, (create)(remove) )
