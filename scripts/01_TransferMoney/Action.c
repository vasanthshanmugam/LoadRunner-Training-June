Action()
{

	lr_start_transaction("01_01_LandingPage");

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Accept-Language", 
		"en-US,en;q=0.9");

	web_url("advantageonlinebanking.com", 
		"URL=https://{host_advantageonlinebanking_com}/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("products", 
		"URL=https://{host_advantageonlinebanking_com}/api/stocks/products?", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{host_advantageonlinebanking_com}/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("bank", 
		"URL=https://{host_advantageonlinebanking_com}/api/management/bank?", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{host_advantageonlinebanking_com}/", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("currency", 
		"URL=https://{host_advantageonlinebanking_com}/api/currency?from=2026-06-02&to=2026-06-03", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{host_advantageonlinebanking_com}/", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		LAST);

	web_custom_request("NVDA", 
		"URL=https://{host_advantageonlinebanking_com}/api/stocks/products/NVDA?duration=6&period=month", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{host_advantageonlinebanking_com}/", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		LAST);

	web_custom_request("AAPL", 
		"URL=https://{host_advantageonlinebanking_com}/api/stocks/products/AAPL?duration=6&period=month", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{host_advantageonlinebanking_com}/", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		LAST);

	web_custom_request("BABA", 
		"URL=https://{host_advantageonlinebanking_com}/api/stocks/products/BABA?duration=6&period=month", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{host_advantageonlinebanking_com}/", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		LAST);

	lr_end_transaction("01_01_LandingPage",LR_AUTO);

	lr_think_time(20);
	
	lr_start_transaction("01_02_ClickSignIn");

	web_add_cookie("_ga_W08X3SJRS7=GS2.1.s1780606532$o1$g0$t1780606532$j60$l0$h0; DOMAIN=advantageonlinebanking.com");

	web_add_cookie("_ga=GA1.1.1612503137.1780606532; DOMAIN=advantageonlinebanking.com");

	
	
		web_reg_save_param_json(
		"ParamName=token",
		"QueryString=$.token",
		SEARCH_FILTERS,
	"Scope=BODY",
		LAST);

	web_custom_request("login", 
		"URL=https://{host_advantageonlinebanking_com}/api/users/login", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{host_advantageonlinebanking_com}/", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"username\":\"{Username}\",\"password\":\"{Password}\"}", 
		LAST);

	

	web_custom_request("currencies", 
		"URL=https://{host_advantageonlinebanking_com}/api/currencies?", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{host_advantageonlinebanking_com}/", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	
	web_set_user("advantageonlinebanking.com\\one", "Oneoneone1", "advantageonlinebanking.com:443");
	
	web_add_header("Authorization", "Bearer {token}");
	web_custom_request("accounts", 
		"URL=https://{host_advantageonlinebanking_com}/api/accounts?", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{host_advantageonlinebanking_com}/dashboard", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);
web_add_header("Authorization", "Bearer {token}");
	web_custom_request("summary", 
		"URL=https://{host_advantageonlinebanking_com}/api/stocks/portfolio/summary?", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{host_advantageonlinebanking_com}/dashboard", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

web_add_header("Authorization", "Bearer {token}");
	web_custom_request("cards", 
		"URL=https://{host_advantageonlinebanking_com}/api/cards?", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{host_advantageonlinebanking_com}/dashboard", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

//web_add_header("Authorization", "Bearer {token}");
//	web_custom_request("3", 
//		"URL=https://{host_advantageonlinebanking_com}/api/forecasts/3?", 
//		"Method=GET", 
//		"TargetFrame=", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{host_advantageonlinebanking_com}/dashboard", 
//		"Snapshot=t13.inf", 
//		"Mode=HTML", 
//		LAST);
//web_add_header("Authorization", "Bearer {token}");
//	web_custom_request("last-month", 
//		"URL=https://{host_advantageonlinebanking_com}/api/forecasts/expense/last-month?", 
//		"Method=GET", 
//		"TargetFrame=", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{host_advantageonlinebanking_com}/dashboard", 
//		"Snapshot=t14.inf", 
//		"Mode=HTML", 
//		LAST);

	lr_end_transaction("01_02_ClickSignIn",LR_AUTO);
	
	lr_think_time(20);

	lr_start_transaction("01_03_ClickNewTransfer");

	web_add_cookie("_ga_W08X3SJRS7=GS2.1.s1780606532$o1$g1$t1780606548$j44$l0$h0; DOMAIN=advantageonlinebanking.com");

	web_custom_request("merchants", 
		"URL=https://{host_advantageonlinebanking_com}/api/users/merchants?", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{host_advantageonlinebanking_com}/new-transfer", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);
	
	
	web_reg_save_param("fromAccount",
    "LB=\"iban\":\"", "RB=\"",
    "Ord=1",
    "NotFound=ERROR",
    "Search=Body",
    LAST);

web_reg_save_param("toAccount",
    "LB=\"iban\":\"", "RB=\"",
    "Ord=2",
    "NotFound=ERROR",
    "Search=Body",
    LAST);
	
web_add_header("Authorization", "Bearer {token}");
	web_custom_request("accounts_2", 
		"URL=https://{host_advantageonlinebanking_com}/api/accounts?", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{host_advantageonlinebanking_com}/new-transfer", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);
		
			lr_output_message("fromAccount = %s", lr_eval_string("{fromAccount}"));
lr_output_message("toAccount   = %s", lr_eval_string("{toAccount}"));

	web_add_cookie("_ga_W08X3SJRS7=GS2.1.s1780606532$o1$g1$t1780606599$j60$l0$h0; DOMAIN=advantageonlinebanking.com");
web_add_header("Authorization", "Bearer {token}");
	web_custom_request("previous-recipients", 
		"URL=https://{host_advantageonlinebanking_com}/api/accounts/{fromAccount}/previous-recipients?", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{host_advantageonlinebanking_com}/new-transfer", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("01_03_ClickNewTransfer",LR_AUTO);
	
	lr_think_time(20);

	lr_start_transaction("01_04_Click_TransferToMyOwnAccount");

	

	web_add_cookie("_ga_W08X3SJRS7=GS2.1.s1780606532$o1$g1$t1780606676$j60$l0$h0; DOMAIN=advantageonlinebanking.com");
web_add_header("Authorization", "Bearer {token}");
	web_custom_request("transactions-own", 
		"URL=https://{host_advantageonlinebanking_com}/api/accounts/{fromAccount}/transactions-own", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{host_advantageonlinebanking_com}/new-transfer", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"iban\":\"{fromAccount}\",\"balance\":344245.95,\"recipient\":{\"iban\":\"{toAccount}\",\"name\":\"Njabulo\",\"bankName\":\"Advantage Bank\",\"bic\":\"ADVB\",\"company_id\":null,\"company_type\":null},\"amount\":1000,\"currencyCode\":\"USD\",\"description\":\"FinalDay-Training\",\"transaction_type\":\"other\"}", 
		LAST);

	web_custom_request("demo", 
		"URL=https://{host_advantageonlinebanking_com}/api/management/demo?", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{host_advantageonlinebanking_com}/accounts", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		LAST);
web_add_header("Authorization", "Bearer {token}");
	web_custom_request("accounts_3", 
		"URL=https://{host_advantageonlinebanking_com}/api/accounts?", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{host_advantageonlinebanking_com}/accounts", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("01_04_Click_TransferToMyOwnAccount",LR_AUTO);

lr_think_time(20);

	lr_start_transaction("01_05_ClickDashboard");

	web_add_cookie("_ga_W08X3SJRS7=GS2.1.s1780606532$o1$g1$t1780606678$j58$l0$h0; DOMAIN=advantageonlinebanking.com");
web_add_header("Authorization", "Bearer {token}");
	web_custom_request("cards_2", 
		"URL=https://{host_advantageonlinebanking_com}/api/cards?", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{host_advantageonlinebanking_com}/dashboard", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		LAST);
web_add_header("Authorization", "Bearer {token}");
	web_custom_request("dashboard", 
		"URL=https://{host_advantageonlinebanking_com}/api/accounts/dashboard?", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{host_advantageonlinebanking_com}/dashboard", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);
web_add_header("Authorization", "Bearer {token}");
	web_custom_request("dashboard_2", 
		"URL=https://{host_advantageonlinebanking_com}/api/cards/dashboard?", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{host_advantageonlinebanking_com}/dashboard", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);


//web_add_header("Authorization", "Bearer {token}");
//	web_custom_request("3_2", 
//		"URL=https://{host_advantageonlinebanking_com}/api/forecasts/3?", 
//		"Method=GET", 
//		"TargetFrame=", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{host_advantageonlinebanking_com}/dashboard", 
//		"Snapshot=t24.inf", 
//		"Mode=HTML", 
//		LAST);


web_add_header("Authorization", "Bearer {token}");
	web_custom_request("accounts_4", 
		"URL=https://{host_advantageonlinebanking_com}/api/accounts?", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{host_advantageonlinebanking_com}/dashboard", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		LAST);

//web_add_header("Authorization", "Bearer {token}");
//	web_custom_request("last-month_2", 
//		"URL=https://{host_advantageonlinebanking_com}/api/forecasts/expense/last-month?", 
//		"Method=GET", 
//		"TargetFrame=", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{host_advantageonlinebanking_com}/dashboard", 
//		"Snapshot=t26.inf", 
//		"Mode=HTML", 
//		LAST);

	lr_end_transaction("06_ClickDashboard",LR_AUTO);

	lr_think_time(20);
	
	lr_start_transaction("07_ClickViewAllTransactions");

	web_add_cookie("_ga_W08X3SJRS7=GS2.1.s1780606532$o1$g1$t1780606699$j37$l0$h0; DOMAIN=advantageonlinebanking.com");
web_add_header("Authorization", "Bearer {token}");
	web_custom_request("transactions", 
		"URL=https://{host_advantageonlinebanking_com}/api/accounts/AB47ADVB331780566257773/transactions?from=2026-05-04&iban=AB47ADVB331780566257773&to=2026-06-04&transaction_type=all", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{host_advantageonlinebanking_com}/accounts/transactions", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		LAST);
web_add_header("Authorization", "Bearer {token}");
	web_custom_request("accounts_5", 
		"URL=https://{host_advantageonlinebanking_com}/api/accounts?", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{host_advantageonlinebanking_com}/accounts/transactions", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		LAST);

web_add_header("Authorization", "Bearer {token}");
	web_custom_request("cards_3", 
		"URL=https://{host_advantageonlinebanking_com}/api/cards?", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{host_advantageonlinebanking_com}/accounts/transactions", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("07_ClickViewAllTransactions",LR_AUTO);


	return 0;
}