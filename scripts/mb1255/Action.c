Action()
{
	
	
	/*
	 				EVO (script da release 45)
	 				Author: Paolo Sala
	 				Per funzionare correttamente accesrtarsi che questi parametri siano settati in EVO:
	 				- anzianità banco posta (Facoltativa: F)
	 				- email in anagrafica (Facoltativa: F)
	 				- anzianità indirizzo (Facoltativa: F)
	 
	 				Accertarsi anbche che nel file di parametri tutte le utenze abbiano come tipo di pagamento BP invece che RI.
	 
	 */

	/* ssl
	*/

	lr_start_transaction("00_Global");
	
	web_set_sockets_option("SSL_VERSION", "TLS1.1");

	web_add_auto_header("User-Agent", 
		"Mozilla/5.0 (Windows NT 6.3; WOW64; rv:41.0) Gecko/20100101 Firefox/41.0");

	lr_start_transaction("01_Homepage");

	web_reg_find("Text=Compass - login",
		LAST);


	web_url("{zz00LoginApp}", 
		"URL={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_start(NULL);

	web_url("jquery-1.4.2.min.js", 
		"URL={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/jquery-1.4.2.min.js", 
		"Resource=1", 
		"RecContentType=text/javascript", 
		"Referer={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/", 
		"Snapshot=t2.inf", 
		LAST);

	web_url("main.css", 
		"URL={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/css/main.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/", 
		"Snapshot=t3.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_concurrent_start(NULL);

	web_url("sf_body.jpg", 
		"URL={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/img/sf_body.jpg", 
		"Resource=1", 
		"RecContentType=image/jpeg", 
		"Referer={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/css/main.css", 
		"Snapshot=t4.inf", 
		LAST);

	web_url("logo_compass.jpg", 
		"URL={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/img/logo_compass.jpg", 
		"Resource=1", 
		"RecContentType=image/jpeg", 
		"Referer={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/css/main.css", 
		"Snapshot=t5.inf", 
		LAST);

	web_url("logo_club.jpg", 
		"URL={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/img/logo_club.jpg", 
		"Resource=1", 
		"RecContentType=image/jpeg", 
		"Referer={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/css/main.css", 
		"Snapshot=t6.inf", 
		LAST);

	web_url("sf_content.gif", 
		"URL={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/img/sf_content.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/css/main.css", 
		"Snapshot=t7.inf", 
		LAST);

	web_url("sf_h1.jpg", 
		"URL={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/img/sf_h1.jpg", 
		"Resource=1", 
		"RecContentType=image/jpeg", 
		"Referer={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/css/main.css", 
		"Snapshot=t8.inf", 
		LAST);

	web_url("help.jpg", 
		"URL={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/img/help.jpg", 
		"Resource=1", 
		"RecContentType=image/jpeg", 
		"Referer={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/css/main.css", 
		"Snapshot=t9.inf", 
		LAST);

	web_url("btn_login.jpg", 
		"URL={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/img/btn_login.jpg", 
		"Resource=1", 
		"RecContentType=image/jpeg", 
		"Referer={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/css/main.css", 
		"Snapshot=t10.inf", 
		LAST);

	web_url("footer.gif", 
		"URL={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/img/footer.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/css/main.css", 
		"Snapshot=t11.inf", 
		LAST);

	web_url("favicon.ico", 
		"URL={zz00Protocol}://{zz00Ambiente}/favicon.ico", 
		"Resource=1", 
		"Referer=", 
		"Snapshot=t12.inf", 
		LAST);

	web_concurrent_end(NULL);

		lr_end_transaction("01_Homepage", LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("02_Login");
	
	web_reg_find("Text=Compass - login",
		LAST);

	
	
	/* login */

	lr_save_string(lr_decrypt("56ea7d685aec8e407fc7234f5d"), "PasswordParameter");

	lr_save_string(lr_decrypt("56ea7d68e"), "PasswordParameter_2");

//	lr_think_time(31);

/*Correlation comment - Do not change!  Original value='SYSSETT0' Name ='system' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=system",
		"RegExp=name=\"system\"\\ \\ value=\"(.*?)\">\\\r\\\n\\\t<input\\ type",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		LAST);
		
		
		
		
		web_reg_save_param("URL_EVO",
		"LB=formEvo\" action=\"{zz00Protocol}://{zz00Ambiente}/",
		"RB=/feest/LoginEsterna",
		LAST);




	web_submit_data("LoginEvoServlet", 
		"Action={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/LoginEvoServlet", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/", 
		"Snapshot=t13.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=ambiente", "Value=0", ENDITEM, 
		"Name=user", "Value={Username}", ENDITEM, 
		"Name=pwd", "Value={PasswordParameter}", ENDITEM, 
		"Name=newpwd", "Value={PasswordParameter_2}", ENDITEM, 
		"Name=newpwd2", "Value=", ENDITEM, 
		LAST);

	lr_save_string(lr_decrypt("56ea7d685aec8e407fc7234f5d"), "PasswordParameter");

	lr_save_string(lr_decrypt("56ea7d68e"), "PasswordParameter_2");

/*Correlation comment - Do not change!  Original value='1458207455199' Name ='TIMESTAMP' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=TIMESTAMP",
		"RegExp=TIMESTAMP=(.*?)';\"\\)",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		LAST);
		
		
	

	web_submit_data("LoginEsterna",
		"Action={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/LoginEsterna",
		"Method=POST",
		"RecContentType=text/html",
		"Referer={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/LoginEvoServlet",
		"Snapshot=t14.inf",
		"Mode=HTTP",
		ITEMDATA,
		"Name=tipo_login", "Value=", ENDITEM,
		"Name=user", "Value={Username}", ENDITEM,
		"Name=pwd", "Value={PasswordParameter}", ENDITEM,
		"Name=newpwd", "Value={PasswordParameter_2}", ENDITEM,
		"Name=env", "Value=DEMOC", ENDITEM,
		"Name=terminale", "Value=TERMINALE", ENDITEM,
		"Name=system", "Value={system}", ENDITEM,
		"Name=internet_canale", "Value=", ENDITEM,
		"Name=internet_menu_centrale", "Value=", ENDITEM,
		"Name=internet_intermediario", "Value=", ENDITEM,
		"Name=internet_abi", "Value=", ENDITEM,
		"Name=internet_cab", "Value=", ENDITEM,
		"Name=internet_codice_interno", "Value=", ENDITEM,
		"Name=interno_create", "Value=N", ENDITEM,
		"Name=interno_user", "Value=", ENDITEM,
		"Name=interno_riferimento_sicurezza", "Value=", ENDITEM,
		"Name=internet_user", "Value={Username}", ENDITEM,
		"Name=internet_create", "Value=", ENDITEM,
		"Name=urlritorno", "Value={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/", ENDITEM,
		"Name=urlRitornoErrore", "Value={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/", ENDITEM,
		LAST);

/*Correlation comment - Do not change!  Original value='20160229092913' Name ='p' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=p",
		"RegExp=href=\"\\.\\./ocint/ocs\\.css\\?p=(.*?)\"\\ type",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		LAST);

	web_url("feest.jsp",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/LoginEsterna",
		"Snapshot=t15.inf",
		"Mode=HTTP",
		LAST);

	web_concurrent_start(NULL);

	web_url("ocs.css",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/ocs.css?p={p}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t16.inf",
		LAST);

	web_url("window.css",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/window.css?p={p}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t17.inf",
		LAST);

	web_url("menu.css",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/menu.css?p={p}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t18.inf",
		LAST);

	web_url("menuCentrale.css",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/menuCentrale.css?p={p}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t19.inf",
		LAST);

	web_url("grid.css",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/grid.css?p={p}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t20.inf",
		LAST);

	web_url("checkbox.css",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/checkbox.css?p={p}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t21.inf",
		LAST);

	web_url("button.css",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/button.css?p={p}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t22.inf",
		LAST);

	web_url("blocchi.css",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/blocchi.css?p={p}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t23.inf",
		LAST);

	web_url("textfield.css",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/textfield.css?p={p}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t24.inf",
		LAST);

	web_url("label.css",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/label.css?p={p}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t25.inf",
		LAST);

	web_url("sezioni.css",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/sezioni.css?p={p}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t26.inf",
		LAST);

	web_url("tabbedpage.css",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/tabbedpage.css?p={p}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t27.inf",
		LAST);

	web_url("dropdown.css",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/dropdown.css?p={p}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t28.inf",
		LAST);

	web_url("radioButton.css",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/radioButton.css?p={p}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t29.inf",
		LAST);

	web_url("textarea.css",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/textarea.css?p={p}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t30.inf",
		LAST);

	web_url("strategy.css",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/strategy.css?p={p}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t31.inf",
		LAST);

	web_url("menu.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/OCSGraphics/menu.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t32.inf",
		LAST);

	web_url("menuBeevo.css",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/menuBeevo.css?p={p}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t33.inf",
		LAST);

	web_url("events.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/OCSGraphics/events.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t34.inf",
		LAST);

	web_url("utils.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/OCSGraphics/utils.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t35.inf",
		LAST);

	web_url("dragdrop.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/OCSGraphics/dragdrop.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t36.inf",
		LAST);

	web_url("dropdownlist.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/OCSGraphics/dropdownlist.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t37.inf",
		LAST);

	web_url("labelVariabili.css",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/labelVariabili.css?p={p}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t38.inf",
		LAST);

	web_url("grid.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/OCSGraphics/grid.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t39.inf",
		LAST);

	web_url("gridSez.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/OCSGraphics/gridSez.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t40.inf",
		LAST);

	web_url("tooltip.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/OCSGraphics/tooltip.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t41.inf",
		LAST);

	web_url("window.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/OCSGraphics/window.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t42.inf",
		LAST);

	web_url("sezione.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/OCSGraphics/sezione.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t43.inf",
		LAST);

	web_url("tabbedpage.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/OCSGraphics/tabbedpage.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t44.inf",
		LAST);

	web_url("gridKernel.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/OCSGraphics/gridKernel.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t45.inf",
		LAST);

	web_url("append.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/OCSGraphics/append.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t46.inf",
		LAST);

	web_url("ocsApiInt.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/scripts/ocsApiInt.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t47.inf",
		LAST);

	web_url("globalContainer.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/scripts/globalContainer.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t48.inf",
		LAST);

	web_url("connection.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/scripts/connection.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t49.inf",
		LAST);

	web_url("feest.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/scripts/feest.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t50.inf",
		LAST);

	web_url("activeJobs.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/scripts/activeJobs.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t51.inf",
		LAST);

	web_url("drawObj.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/OCSGraphics/drawObj.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t52.inf",
		LAST);

	web_url("treeMenu.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/scripts/treeMenu.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t53.inf",
		LAST);

	web_url("static.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/Strategy/Object/static.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t54.inf",
		LAST);

	web_url("strategyEnv_method.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/Strategy/strategyEnv_method.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t55.inf",
		LAST);

	web_url("mouseMenu.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/OCSGraphics/mouseMenu.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t56.inf",
		LAST);

	web_url("strings.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/Strategy/Object/strings.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t57.inf",
		LAST);

	web_url("ExitNode.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/Strategy/Object/ExitNode.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t58.inf",
		LAST);

	web_url("ExitStrategyNode.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/Strategy/Object/ExitStrategyNode.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t59.inf",
		LAST);

	web_url("ExitSubNode.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/Strategy/Object/ExitSubNode.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t60.inf",
		LAST);

	web_url("MyLink.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/Strategy/Object/MyLink.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t61.inf",
		LAST);

	web_url("StategyNode.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/Strategy/Object/StategyNode.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t62.inf",
		LAST);

	web_url("strategy.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/Strategy/strategy.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t63.inf",
		LAST);

	web_concurrent_end(NULL);

	web_concurrent_start(NULL);

	web_url("ff.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/OCSGraphics/ff.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t64.inf",
		LAST);

	web_url("ff.css",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/ff.css?p={p}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t65.inf",
		LAST);

	web_url("OCINT_newBG_GREY.png",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/OCINT_newBG_GREY.png",
		"Resource=1",
		"RecContentType=image/png",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/ocs.css?p={p}",
		"Snapshot=t66.inf",
		LAST);

	web_url("loading1.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/window/loading1.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/ocs.css?p={p}",
		"Snapshot=t67.inf",
		LAST);

	web_concurrent_end(NULL);

	web_add_auto_header("Pragma", 
		"no-cache");

	web_custom_request("FeestServlet",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t68.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=initialize~~jobnum=~~task=~~videata=~~id=~~attr=1~~tipo=~~data=",
		LAST);

	web_concurrent_start(NULL);

	web_url("OCINT_mainmenu.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/menu/OCINT_mainmenu.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/menu.css?p={p}",
		"Snapshot=t69.inf",
		LAST);

	web_url("OCINT_menuElementsContainerBg.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/menu/OCINT_menuElementsContainerBg.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/menu.css?p={p}",
		"Snapshot=t70.inf",
		LAST);

	web_url("OCINT_sessionInfoDivIcon.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/OCINT_sessionInfoDivIcon.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/menu.css?p={p}",
		"Snapshot=t71.inf",
		LAST);

	web_url("OCINT_arrow.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/menu/OCINT_arrow.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/menu.css?p={p}",
		"Snapshot=t72.inf",
		LAST);

	web_concurrent_end(NULL);

	/* cerca cliente */

	//lr_think_time(5);
	
	
	

	lr_end_transaction("02_Login", LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("03_AccessoPerCliente");
	
	

	
	web_custom_request("FeestServlet_2",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t73.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=replycheck",
		LAST);
	
	
	
	web_reg_save_param("TIMESTAMP_2",
		"LB=TIMESTAMP=",
		"RB='",
		LAST);
	
		
	web_reg_save_param("JOB",
		"LB=('",
		"RB=.TK000003B1",
		LAST);

	web_custom_request("FeestServlet_3",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t74.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=command~~jobnum= ~~task= ~~videata= ~~id=MIFEINIT02~~attr=mousedown~~tipo=~~data=",
		LAST);

	web_concurrent_start(NULL);

	web_url("OCINT_statusBar.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/window/OCINT_statusBar.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/window.css?p={p}",
		"Snapshot=t75.inf",
		LAST);

	web_url("OCINT_winbar.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/window/OCINT_winbar.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/window.css?p={p}",
		"Snapshot=t76.inf",
		LAST);

	web_url("OCINT_1.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/window/OCINT_1.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/window.css?p={p}",
		"Snapshot=t77.inf",
		LAST);

	web_url("OCINT_resize.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/compass-demo/images/feest/window/OCINT_resize.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/compass-demo/ocint/window.css?p={p}",
		"Snapshot=t78.inf",
		LAST);

	web_url("OCINT_titlePar2.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/window/OCINT_titlePar2.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/window.css?p={p}",
		"Snapshot=t79.inf",
		LAST);

	web_url("OCINT_minimize.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/window/OCINT_minimize.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/window.css?p={p}",
		"Snapshot=t80.inf",
		LAST);

	web_concurrent_end(NULL);

	web_revert_auto_header("Pragma");

	web_url("VideataServlet",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_2}",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t81.inf",
		"Mode=HTTP",
		LAST);

	web_concurrent_start(NULL);

	web_url("ocs.css_2",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/ocs.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_2}",
		"Snapshot=t82.inf",
		LAST);

	web_url("menu.css_2",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/menu.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_2}",
		"Snapshot=t83.inf",
		LAST);

	web_url("iframe.css",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/iframe.css?p={p}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_2}",
		"Snapshot=t84.inf",
		LAST);

	web_url("grid.css_2",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/grid.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_2}",
		"Snapshot=t85.inf",
		LAST);

	web_url("checkbox.css_2",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/checkbox.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_2}",
		"Snapshot=t86.inf",
		LAST);

	web_url("button.css_2",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/button.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_2}",
		"Snapshot=t87.inf",
		LAST);

	web_url("blocchi.css_2",
		"URL={zz00Protocol}://{zz00Ambiente}/compass-demo/ocint/blocchi.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/compass-demo/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_2}",
		"Snapshot=t88.inf",
		LAST);

	web_url("textfield.css_2",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/textfield.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_2}",
		"Snapshot=t89.inf",
		LAST);

	web_url("questionari.css",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/questionari.css?p={p}",
		"Resource=1",
		"RecContentType=text/css",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_2}",
		"Snapshot=t90.inf",
		LAST);

	web_url("label.css_2",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/label.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_2}",
		"Snapshot=t91.inf",
		LAST);

	web_url("labelVariabili.css_2",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/labelVariabili.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_2}",
		"Snapshot=t92.inf",
		LAST);

	web_url("sezioni.css_2",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/sezioni.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_2}",
		"Snapshot=t93.inf",
		LAST);

	web_url("tabbedpage.css_2",
		"URL={zz00Protocol}://{zz00Ambiente}/compass-demo/ocint/tabbedpage.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/compass-demo/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_2}",
		"Snapshot=t94.inf",
		LAST);

	web_url("dropdown.css_2",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/dropdown.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_2}",
		"Snapshot=t95.inf",
		LAST);

	web_url("radioButton.css_2",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/radioButton.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_2}",
		"Snapshot=t96.inf",
		LAST);

	web_url("textarea.css_2",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/textarea.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_2}",
		"Snapshot=t97.inf",
		LAST);

	web_url("strategy.css_2",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/strategy.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_2}",
		"Snapshot=t98.inf",
		LAST);

	web_url("iframe.js",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/scripts/iframe.js?p={p}",
		"Resource=1",
		"RecContentType=text/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_2}",
		"Snapshot=t99.inf",
		LAST);

	web_url("ff.css_2",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/ff.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_2}",
		"Snapshot=t100.inf",
		LAST);

	web_concurrent_end(NULL);

	web_concurrent_start(NULL);

	web_url("collapseGray.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/section/collapseGray.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/sezioni.css?p={p}",
		"Snapshot=t101.inf",
		LAST);

	web_url("OCINT_esci.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/button/OCINT_esci.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/button.css?p={p}",
		"Snapshot=t102.inf",
		LAST);

	web_url("OCINT_conferma_prosegui.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/button/OCINT_conferma_prosegui.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/button.css?p={p}",
		"Snapshot=t103.inf",
		LAST);

	web_url("OCINT_livello1.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/menu/OCINT_livello1.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/menu.css?p={p}",
		"Snapshot=t104.inf",
		LAST);

	web_concurrent_end(NULL);

	web_add_auto_header("Pragma", 
		"no-cache");

	web_custom_request("FeestServlet_4",
		"URL={zz00Protocol}://{zz00Ambiente}/compass-demo/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/compass-demo/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t105.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=check~~jobnum={JOB}~~task=~~videata=~~id=~~attr=~~tipo=~~data=",
		LAST);

	/* cerca */

	lr_end_transaction("03_AccessoPerCliente", LR_AUTO);
	
	lr_think_time(3);

	lr_start_transaction("04_RicercaCliente");

	web_reg_save_param("TIMESTAMP_3",
		"LB=TIMESTAMP=",
		"RB='",
		LAST);

	
	

	web_custom_request("FeestServlet_5",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t106.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"BodyBinary=method=feestrequest~~azione=pacchettoRichieste~~jobnum={JOB}~~data=(valorizzazione$&,$&{JOB}$&,$&TK000003B1$&,$&RicAna$&,$&TF00000010$&,$&$&,$&TF00000010@\\xC2\\xA3%{CodiceCliente}$&,$&)$,$(command$&,$&{JOB}$&,$&TK000003B1$&,$&RicAna$&,$&BT00000042$&,$&mousedown$&,$&$&,$&)",
		LAST);

	
			web_reg_find("Text=Anagrafica",
		LAST);
	web_revert_auto_header("Pragma");

	web_url("VideataServlet_2",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_3}",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t107.inf",
		"Mode=HTTP",
		LAST);

	web_concurrent_start(NULL);

	web_url("ocs.css_3",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/ocs.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_3}",
		"Snapshot=t108.inf",
		LAST);

	web_url("menu.css_3",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/menu.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_3}",
		"Snapshot=t109.inf",
		LAST);

	web_url("iframe.css_2",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/iframe.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_3}",
		"Snapshot=t110.inf",
		LAST);

	web_url("grid.css_3",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/grid.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_3}",
		"Snapshot=t111.inf",
		LAST);

	web_url("checkbox.css_3",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/checkbox.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_3}",
		"Snapshot=t112.inf",
		LAST);

	web_url("blocchi.css_3",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/blocchi.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_3}",
		"Snapshot=t113.inf",
		LAST);

	web_url("button.css_3",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/button.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_3}",
		"Snapshot=t114.inf",
		LAST);

	web_url("textfield.css_3",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/textfield.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_3}",
		"Snapshot=t115.inf",
		LAST);

	web_url("label.css_3",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/label.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_3}",
		"Snapshot=t116.inf",
		LAST);

	web_url("questionari.css_2",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/questionari.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_3}",
		"Snapshot=t117.inf",
		LAST);

	web_url("labelVariabili.css_3",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/labelVariabili.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_3}",
		"Snapshot=t118.inf",
		LAST);

	web_url("sezioni.css_3",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/sezioni.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_3}",
		"Snapshot=t119.inf",
		LAST);

	web_url("tabbedpage.css_3",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/tabbedpage.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_3}",
		"Snapshot=t120.inf",
		LAST);

	web_url("dropdown.css_3",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/dropdown.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_3}",
		"Snapshot=t121.inf",
		LAST);

	web_url("radioButton.css_3",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/radioButton.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_3}",
		"Snapshot=t122.inf",
		LAST);

	web_url("strategy.css_3",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/strategy.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_3}",
		"Snapshot=t123.inf",
		LAST);

	web_url("iframe.js_2",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/scripts/iframe.js?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_3}",
		"Snapshot=t124.inf",
		LAST);

	web_url("ff.css_3",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/ff.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_3}",
		"Snapshot=t125.inf",
		LAST);

	web_url("textarea.css_3",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/textarea.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_3}",
		"Snapshot=t126.inf",
		LAST);

	web_concurrent_end(NULL);

	web_concurrent_start(NULL);

	web_url("OCINT_button_blue_bg.png",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/button/OCINT_button_blue_bg.png",
		"Resource=1",
		"RecContentType=image/png",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/button.css?p={p}",
		"Snapshot=t127.inf",
		LAST);

	web_url("gridbar.png",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/section/gridbar.png",
		"Resource=1",
		"RecContentType=image/png",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/grid.css?p={p}",
		"Snapshot=t128.inf",
		LAST);

	web_url("tpLeft.png",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/button/tabbedpage/tpLeft.png",
		"Resource=1",
		"RecContentType=image/png",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/tabbedpage.css?p={p}",
		"Snapshot=t129.inf",
		LAST);

	web_url("tpRight.png",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/button/tabbedpage/tpRight.png",
		"Resource=1",
		"RecContentType=image/png",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/tabbedpage.css?p={p}",
		"Snapshot=t130.inf",
		LAST);

	web_url("sectionbar.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/section/sectionbar.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/tabbedpage.css?p={p}",
		"Snapshot=t131.inf",
		LAST);

	web_url("OCINT_TSTop-title.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/section/OCINT_TSTop-title.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/tabbedpage.css?p={p}",
		"Snapshot=t132.inf",
		LAST);

	web_url("fineRed.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/grid/fineRed.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/grid.css?p={p}",
		"Snapshot=t133.inf",
		LAST);

	web_url("avantiRed.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/grid/avantiRed.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/grid.css?p={p}",
		"Snapshot=t134.inf",
		LAST);

	web_concurrent_end(NULL);

	web_add_auto_header("Pragma", 
		"no-cache");

	web_custom_request("FeestServlet_6",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t135.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=check~~jobnum={JOB}~~task=~~videata=~~id=~~attr=~~tipo=~~data=",
		LAST);

	web_concurrent_start(NULL);

	web_url("indietroRed.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/grid/indietroRed.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/grid.css?p={p}",
		"Snapshot=t136.inf",
		LAST);

	web_url("inizioRed.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/grid/inizioRed.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/grid.css?p={p}",
		"Snapshot=t137.inf",
		LAST);

	web_url("OCINT_grid_bg.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/grid/OCINT_grid_bg.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/grid.css?p={p}",
		"Snapshot=t138.inf",
		LAST);

	web_url("OCINT_TSTop-title-sel.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/section/OCINT_TSTop-title-sel.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/tabbedpage.css?p={p}",
		"Snapshot=t139.inf",
		LAST);

	web_concurrent_end(NULL);

	web_custom_request("FeestServlet_7",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t140.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=check~~jobnum={JOB}~~task=~~videata=~~id=~~attr=~~tipo=~~data=",
		LAST);

	web_custom_request("FeestServlet_8",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t141.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=check~~jobnum={JOB}~~task=~~videata=~~id=~~attr=~~tipo=~~data=",
		LAST);

	//lr_think_time(4);

	web_custom_request("FeestServlet_9",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t142.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=replycheck",
		LAST);

	/* sim fin cons */
	lr_end_transaction("04_RicercaCliente", LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("05_SimFinanziariaConsumo");
	
		web_reg_save_param("TIMESTAMP_4",
		"LB=TIMESTAMP=",
		"RB='",
		LAST);
	
			web_reg_save_param("JOB_3",
		"LB=('",
		"RB=.TK000005C8",
		LAST);

	web_custom_request("FeestServlet_10",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t143.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"BodyBinary=method=feestrequest~~azione=pacchettoRichieste~~jobnum={JOB}~~data=(valorizzazione$&,$&{JOB}$&,$&TK000003B1$&,$&SchedaCli$&,$&TP00000034$&,$&$&,$&TP00000034@\\xC2\\xA3%TS0000005C$&,$&)$,$(command$&,$&{JOB}$&,$&TK000003B1$&,$&SchedaCli$&,$&MI00000219$&,$&mousedown$&,$&$&,$&)",
		LAST);

	web_url("OCINT_2.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/window/OCINT_2.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/window.css?p={p}",
		"Snapshot=t144.inf",
		LAST);
	
				web_reg_find("Text=Dati prefinanziari",
		LAST);

	web_revert_auto_header("Pragma");

	web_url("VideataServlet_3",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_4}",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t145.inf",
		"Mode=HTTP",
		LAST);

	web_concurrent_start(NULL);

	web_url("iframe.css_3",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/iframe.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_4}",
		"Snapshot=t146.inf",
		LAST);

	web_url("ocs.css_4",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/ocs.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_4}",
		"Snapshot=t147.inf",
		LAST);

	web_url("grid.css_4",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/grid.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_4}",
		"Snapshot=t148.inf",
		LAST);

	web_url("menu.css_4",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/menu.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_4}",
		"Snapshot=t149.inf",
		LAST);

	web_url("checkbox.css_4",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/checkbox.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_4}",
		"Snapshot=t150.inf",
		LAST);

	web_url("button.css_4",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/button.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_4}",
		"Snapshot=t151.inf",
		LAST);

	web_url("blocchi.css_4",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/blocchi.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_4}",
		"Snapshot=t152.inf",
		LAST);

	web_url("textfield.css_4",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/textfield.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_4}",
		"Snapshot=t153.inf",
		LAST);

	web_url("questionari.css_3",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/questionari.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_4}",
		"Snapshot=t154.inf",
		LAST);

	web_url("label.css_4",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/label.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_4}",
		"Snapshot=t155.inf",
		LAST);

	web_url("labelVariabili.css_4",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/labelVariabili.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_4}",
		"Snapshot=t156.inf",
		LAST);

	web_url("sezioni.css_4",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/sezioni.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_4}",
		"Snapshot=t157.inf",
		LAST);

	web_url("tabbedpage.css_4",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/tabbedpage.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_4}",
		"Snapshot=t158.inf",
		LAST);

	web_url("dropdown.css_4",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/dropdown.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_4}",
		"Snapshot=t159.inf",
		LAST);

	web_url("radioButton.css_4",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/radioButton.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_4}",
		"Snapshot=t160.inf",
		LAST);

	web_url("textarea.css_4",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/textarea.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_4}",
		"Snapshot=t161.inf",
		LAST);

	web_url("strategy.css_4",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/strategy.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_4}",
		"Snapshot=t162.inf",
		LAST);

	web_url("ff.css_4",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/ff.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_4}",
		"Snapshot=t163.inf",
		LAST);

	web_url("iframe.js_3",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/scripts/iframe.js?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_4}",
		"Snapshot=t164.inf",
		LAST);

	web_concurrent_end(NULL);

	web_concurrent_start(NULL);

	web_url("helpRC.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/button/helpRC.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/button.css?p={p}",
		"Snapshot=t165.inf",
		LAST);

	web_url("freccia-giu.png",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/dropdown/freccia-giu.png",
		"Resource=1",
		"RecContentType=image/png",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/dropdown.css?p={p}",
		"Snapshot=t166.inf",
		LAST);

	web_url("OCINT_sfondoDD-obl.png",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/dropdown/OCINT_sfondoDD-obl.png",
		"Resource=1",
		"RecContentType=image/png",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/dropdown.css?p={p}",
		"Snapshot=t167.inf",
		LAST);

	web_url("sfondoDD.png",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/dropdown/sfondoDD.png",
		"Resource=1",
		"RecContentType=image/png",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/dropdown.css?p={p}",
		"Snapshot=t168.inf",
		LAST);

	web_url("OCINT_freccia-giu-obl.png",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/dropdown/OCINT_freccia-giu-obl.png",
		"Resource=1",
		"RecContentType=image/png",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/dropdown.css?p={p}",
		"Snapshot=t169.inf",
		LAST);

	web_concurrent_end(NULL);

	web_add_auto_header("Pragma", 
		"no-cache");

	web_custom_request("FeestServlet_11",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t170.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=check~~jobnum={JOB_3}~~task=~~videata=~~id=~~attr=~~tipo=~~data=",
		LAST);

	
	lr_end_transaction("05_SimFinanziariaConsumo", LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("06_00_CompilazioneForm_N1");

	lr_start_transaction("06_01_Prodotto");

	
	/* prod */


	web_custom_request("FeestServlet_12",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t171.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"BodyBinary=method=feestrequest~~azione=dynamicLoading~~jobnum={JOB_3}~~task=TK000005C8~~videata=VideoCalc~~id=DD00000005~~attr=CONTROLLO~~tipo=P~~data=DD00000005$0\\xC2\\xA3%  \\xC2\\xA7DD00000005$1\\xC2\\xA3%{Prodotto}",
		LAST);


	web_custom_request("FeestServlet_13",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t172.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=replycheck",
		LAST);

	lr_end_transaction("06_01_Prodotto", LR_AUTO);

	lr_start_transaction("06_02_Bene");

	
	/* descrizione */


	web_url("loading2.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/window/loading2.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/window.css?p={p}",
		"Snapshot=t173.inf",
		LAST);

	web_custom_request("FeestServlet_14",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t174.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"BodyBinary=method=feestrequest~~azione=dynamicLoading~~jobnum={JOB_3}~~task=TK000005C8~~videata=VideoCalc~~id=DD00000006~~attr=CONTROLLO~~tipo=P~~data=DD00000006$0\\xC2\\xA3%   \\xC2\\xA7DD00000006$1\\xC2\\xA3%{BenePrestito}",
		LAST);
	
		lr_end_transaction("06_02_Bene", LR_AUTO);
	
lr_start_transaction("06_03_Descrizione");

	web_url("collapse.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/section/collapse.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/tabbedpage.css?p={p}",
		"Snapshot=t175.inf",
		LAST);

	web_custom_request("FeestServlet_15",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t176.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"BodyBinary=method=feestrequest~~azione=pacchettoRichieste~~jobnum={JOB_3}~~data=(valorizzazione$&,$&{JOB_3}$&,$&TK000005C8$&,$&VideoCalc$&,$&TP00000050$&,$&$&,$&TP00000050@\\xC2\\xA3%TS00000034$&,$&)$,$(dynex$&,$&{JOB_3}$&,$&TK000005C8$&,$&VideoCalc$&,$&$&,$&$&,$&$&,$&)",
		LAST);



	web_custom_request("FeestServlet_16",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t177.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=replycheck",
		LAST);



	web_custom_request("FeestServlet_17",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t178.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=replycheck",
		LAST);



	web_custom_request("FeestServlet_18",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t179.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"BodyBinary=method=feestrequest~~azione=valorizzazione~~jobnum={JOB_3}~~task=TK000005C8~~videata=VideoCalc~~id=TF00000060~~attr=~~tipo=~~data=TF00000060@\\xC2\\xA3%{DescrizioneBene}",
		LAST);



	web_custom_request("FeestServlet_19",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t180.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=replycheck",
		LAST);
		
		
	lr_end_transaction("06_03_Descrizione", LR_AUTO);
	lr_start_transaction("06_04_TabellaFin");

	/* tabella fin */


	web_custom_request("FeestServlet_20",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t181.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"BodyBinary=method=feestrequest~~azione=dynamicLoading~~jobnum={JOB_3}~~task=TK000005C8~~videata=VideoCalc~~id=DD0000007C~~attr=CONTROLLO~~tipo=P~~data=DD0000007C$0\\xC2\\xA3%          \\xC2\\xA7DD0000007C$1\\xC2\\xA3%{TabellaFinanziaria}",
		LAST);

	web_custom_request("FeestServlet_21",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t182.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=dynex~~jobnum={JOB_3}~~task=TK000005C8~~videata=VideoCalc~~id=~~attr=~~tipo=~~data=",
		LAST);

	lr_end_transaction("06_04_TabellaFin", LR_AUTO);


	/* form pag */
	lr_start_transaction("06_05_Pagamento");

	web_custom_request("FeestServlet_22",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t183.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=replycheck",
		LAST);

	web_custom_request("FeestServlet_23",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t184.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"BodyBinary=method=feestrequest~~azione=dynamicLoading~~jobnum={JOB_3}~~task=TK000005C8~~videata=VideoCalc~~id=DD00000215~~attr=CONTROLLO~~tipo=P~~data=DD00000215$0\\xC2\\xA3%  \\xC2\\xA7DD00000215$1\\xC2\\xA3%{ModalitaPagamento}",
		LAST);

	web_custom_request("FeestServlet_24",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t185.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=dynex~~jobnum={JOB_3}~~task=TK000005C8~~videata=VideoCalc~~id=~~attr=~~tipo=~~data=",
		LAST);

	lr_end_transaction("06_05_Pagamento", LR_AUTO);


	/* prestito */

	/* rate */

	lr_start_transaction("06_06_Rate");

	web_custom_request("FeestServlet_25",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t186.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"BodyBinary=method=feestrequest~~azione=pacchettoRichieste~~jobnum={JOB_3}~~data=(valorizzazione$&,$&{JOB_3}$&,$&TK000005C8$&,$&VideoCalc$&,$&TF00000123$&,$&$&,$&TF00000123@\\xC2\\xA3%{Prestito}$&,$&)$,$(dynamicLoading$&,$&{JOB_3}$&,$&TK000005C8$&,$&VideoCalc$&,$&DD00000384$&,$&CONTROLLO$&,$&DD00000384$0\\xC2\\xA3%000\\xC2\\xA7DD00000384$1\\xC2\\xA3%{NumeroRate}$&,$&P)",
		LAST);

	web_custom_request("FeestServlet_26",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t187.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=replycheck",
		LAST);

	web_custom_request("FeestServlet_27",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t188.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"BodyBinary=method=feestrequest~~azione=dynamicLoading~~jobnum={JOB_3}~~task=TK000005C8~~videata=VideoCalc~~id=DD00000385~~attr=CONTROLLO~~tipo=P~~data=DD00000385$0\\xC2\\xA3%000\\xC2\\xA7DD00000385$1\\xC2\\xA3%{NumeroRate}",
		LAST);

	/* stampa privacy */


	lr_end_transaction("06_06_Rate", LR_AUTO);

	lr_end_transaction("06_00_CompilazioneForm_N1", LR_AUTO);

	lr_think_time(5);
	
	lr_start_transaction("07_StampaPrivacy");
		
		web_reg_save_param("TIMESTAMP_5",
		"LB=TIMESTAMP=",
		"RB='",
		LAST);

	web_custom_request("FeestServlet_28",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t189.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=command~~jobnum={JOB_3}~~task=TK000005C8~~videata=VideoCalc~~id=BT00000221~~attr=mousedown~~tipo=~~data=",
		LAST);

	web_revert_auto_header("Pragma");

/*Correlation comment - Do not change!  Original value='SCZZOFF4MT' Name ='CorrelationParameter' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter",
		"RegExp=_\\\d+_([^_]+_\\\d+)_X00000\\.PDF",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		LAST);

	web_url("VideataServlet_4",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_5}",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t190.inf",
		"Mode=HTTP",
		LAST);

	web_concurrent_start(NULL);

	web_url("ocs.css_5",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/ocs.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_5}",
		"Snapshot=t191.inf",
		LAST);

	web_url("blocchi.css_5",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/blocchi.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_5}",
		"Snapshot=t192.inf",
		LAST);

	web_url("textfield.css_5",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/textfield.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_5}",
		"Snapshot=t193.inf",
		LAST);

	web_url("questionari.css_4",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/questionari.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_5}",
		"Snapshot=t194.inf",
		LAST);

	web_url("label.css_5",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/label.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_5}",
		"Snapshot=t195.inf",
		LAST);

	web_url("labelVariabili.css_5",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/labelVariabili.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_5}",
		"Snapshot=t196.inf",
		LAST);

	web_url("sezioni.css_5",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/sezioni.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_5}",
		"Snapshot=t197.inf",
		LAST);

	web_url("tabbedpage.css_5",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/tabbedpage.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_5}",
		"Snapshot=t198.inf",
		LAST);

	web_url("dropdown.css_5",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/dropdown.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_5}",
		"Snapshot=t199.inf",
		LAST);

	web_url("radioButton.css_5",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/radioButton.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_5}",
		"Snapshot=t200.inf",
		LAST);

	web_url("menu.css_5",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/menu.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_5}",
		"Snapshot=t201.inf",
		LAST);

	web_url("textarea.css_5",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/textarea.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_5}",
		"Snapshot=t202.inf",
		LAST);

	web_url("button.css_5",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/button.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_5}",
		"Snapshot=t203.inf",
		LAST);

	web_url("strategy.css_5",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/strategy.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_5}",
		"Snapshot=t204.inf",
		LAST);

	web_url("ff.css_5",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/ff.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_5}",
		"Snapshot=t205.inf",
		LAST);

	web_url("iframe.js_4",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/scripts/iframe.js?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_5}",
		"Snapshot=t206.inf",
		LAST);

	web_url("checkbox.css_5",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/checkbox.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_5}",
		"Snapshot=t207.inf",
		LAST);

	web_url("grid.css_5",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/grid.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_5}",
		"Snapshot=t208.inf",
		LAST);

	web_url("iframe.css_4",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/iframe.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_5}",
		"Snapshot=t209.inf",
		LAST);

	web_concurrent_end(NULL);

	web_add_auto_header("Pragma", 
		"no-cache");

	web_custom_request("FeestServlet_29",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t210.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=check~~jobnum={JOB_3}~~task=~~videata=~~id=~~attr=~~tipo=~~data=",
		LAST);

	web_concurrent_start(NULL);

	web_url("{JOB_3}_000001_SCZZOFF4MT_03172016_X00000.PDF",
		"URL={zz00Protocol}://{zz00Ambiente}/FEEVO/{Username}/{Username}/{JOB_3}_000001_{CorrelationParameter}_X00000.PDF",
		"Resource=1",
		"RecContentType=application/pdf",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_5}",
		"Snapshot=t211.inf",
		LAST);

	web_url("{JOB_3}_000001_SCZZOFF4MT_03172016_X00000.PDF_2",
		"URL={zz00Protocol}://{zz00Ambiente}/FEEVO/{Username}/{Username}/{JOB_3}_000001_{CorrelationParameter}_X00000.PDF",
		"Resource=1",
		"RecContentType=application/pdf",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_5}",
		"Snapshot=t212.inf",
		LAST);

	web_url("{JOB_3}_000001_SCZZOFF4MT_03172016_X00000.PDF_3",
		"URL={zz00Protocol}://{zz00Ambiente}/FEEVO/{Username}/{Username}/{JOB_3}_000001_{CorrelationParameter}_X00000.PDF",
		"Resource=1",
		"RecContentType=application/pdf",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_5}",
		"Snapshot=t213.inf",
		LAST);

	web_url("{JOB_3}_000001_SCZZOFF4MT_03172016_X00000.PDF_4",
		"URL={zz00Protocol}://{zz00Ambiente}/FEEVO/{Username}/{Username}/{JOB_3}_000001_{CorrelationParameter}_X00000.PDF",
		"Resource=1",
		"RecContentType=application/pdf",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_5}",
		"Snapshot=t214.inf",
		LAST);

	web_url("{JOB_3}_000001_SCZZOFF4MT_03172016_X00000.PDF_5",
		"URL={zz00Protocol}://{zz00Ambiente}/FEEVO/{Username}/{Username}/{JOB_3}_000001_{CorrelationParameter}_X00000.PDF",
		"Resource=1",
		"RecContentType=application/pdf",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_5}",
		"Snapshot=t215.inf",
		LAST);

	web_concurrent_end(NULL);

	
	
	lr_end_transaction("07_StampaPrivacy", LR_AUTO);
	
	


	/* esci */

	lr_think_time(6);
	
	lr_start_transaction("08_EsciPrivacy");


//	lr_think_time(6);

	web_custom_request("FeestServlet_30",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t216.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=command~~jobnum={JOB_3}~~task=TK00000275~~videata=VisStampe~~id=BT00000274~~attr=mousedown~~tipo=~~data=",
		LAST);

	web_custom_request("FeestServlet_31",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t217.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=dynex~~jobnum={JOB_3}~~task=TK000005C8~~videata=VideoCalc~~id=~~attr=~~tipo=~~data=",
		LAST);

	web_custom_request("FeestServlet_32",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t218.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=replycheck",
		LAST);
	lr_end_transaction("08_EsciPrivacy", LR_AUTO);
	


	/* prosegui */

	lr_think_time(5);
	
	lr_start_transaction("09_Prosegui");

	web_custom_request("FeestServlet_33",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t219.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=command~~jobnum={JOB_3}~~task=TK000005C8~~videata=VideoCalc~~id=BT0000003D~~attr=mousedown~~tipo=~~data=",
		LAST);

	web_concurrent_start(NULL);

	web_url("fineGray.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/grid/fineGray.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/grid.css?p={p}",
		"Snapshot=t220.inf",
		LAST);

	web_url("indietroGray.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/grid/indietroGray.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/grid.css?p={p}",
		"Snapshot=t221.inf",
		LAST);

	web_url("inizioGray.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/grid/inizioGray.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/grid.css?p={p}",
		"Snapshot=t222.inf",
		LAST);

	web_url("avantiGray.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/compass-demo/images/feest/grid/avantiGray.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/compass-demo/ocint/grid.css?p={p}",
		"Snapshot=t223.inf",
		LAST);

	web_url("OCINT_back.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/button/OCINT_back.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/button.css?p={p}",
		"Snapshot=t224.inf",
		LAST);

	web_concurrent_end(NULL);

	web_custom_request("FeestServlet_34",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t225.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=dynamicLoading~~jobnum={JOB_3}~~task=TK000005C8~~videata=VideoCalc~~id=GD0000017B~~attr=CARICAMENTO~~tipo=~~data=",
		LAST);

	web_custom_request("FeestServlet_35",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t226.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=dynex~~jobnum={JOB_3}~~task=TK000005C8~~videata=VideoCalc~~id=~~attr=~~tipo=~~data=",
		LAST);

	/* prosegui */
	lr_end_transaction("09_Prosegui", LR_AUTO);

	/* prosegui */

	lr_think_time(5);

	
	lr_start_transaction("10_Prosegui");

	web_custom_request("FeestServlet_36",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t227.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=command~~jobnum={JOB_3}~~task=TK000005C8~~videata=VideoCalc~~id=BT00000198~~attr=mousedown~~tipo=~~data=",
		LAST);

	web_custom_request("FeestServlet_37",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t228.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=dynamicLoading~~jobnum={JOB_3}~~task=TK000005C8~~videata=VideoCalc~~id=GD0000017B~~attr=CARICAMENTO~~tipo=~~data=",
		LAST);

	web_custom_request("FeestServlet_38",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t229.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=dynamicLoading~~jobnum={JOB_3}~~task=TK000005C8~~videata=VideoCalc~~id=GD0000017F~~attr=CARICAMENTO~~tipo=~~data=",
		LAST);

	web_custom_request("FeestServlet_39",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t230.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=dynex~~jobnum={JOB_3}~~task=TK000005C8~~videata=VideoCalc~~id=~~attr=~~tipo=~~data=",
		LAST);

	web_custom_request("FeestServlet_40",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t231.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=replycheck",
		LAST);

	/* stampa secci */
	
		
	lr_end_transaction("10_Prosegui", LR_AUTO);


	/* stampa secci */
	
	lr_start_transaction("11_StampaSecci");

	
			web_reg_save_param("TIMESTAMP_6",
		"LB=TIMESTAMP=",
		"RB='",
		LAST);
	
	web_custom_request("FeestServlet_41",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t232.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=command~~jobnum={JOB_3}~~task=TK000005C8~~videata=VideoCalc~~id=BT00000322~~attr=mousedown~~tipo=~~data=",
		LAST);

	web_revert_auto_header("Pragma");

/*Correlation comment - Do not change!  Original value='000002_SCZZOFPNST_03172016_X00000' Name ='CorrelationParameter_1' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter_1",
		"RegExp=\\\d+_(.*?)\\.PDF",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		LAST);

	web_url("VideataServlet_5",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_6}",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t233.inf",
		"Mode=HTTP",
		LAST);

	web_concurrent_start(NULL);

	web_url("ocs.css_6",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/ocs.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_6}",
		"Snapshot=t234.inf",
		LAST);

	web_url("menu.css_6",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/menu.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_6}",
		"Snapshot=t235.inf",
		LAST);

	web_url("iframe.css_5",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/iframe.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_6}",
		"Snapshot=t236.inf",
		LAST);

	web_url("checkbox.css_6",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/checkbox.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_6}",
		"Snapshot=t237.inf",
		LAST);

	web_url("grid.css_6",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/grid.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_6}",
		"Snapshot=t238.inf",
		LAST);

	web_url("button.css_6",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/button.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_6}",
		"Snapshot=t239.inf",
		LAST);

	web_url("label.css_6",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/label.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_6}",
		"Snapshot=t240.inf",
		LAST);

	web_url("blocchi.css_6",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/blocchi.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_6}",
		"Snapshot=t241.inf",
		LAST);

	web_url("questionari.css_5",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/questionari.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_6}",
		"Snapshot=t242.inf",
		LAST);

	web_url("textfield.css_6",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/textfield.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_6}",
		"Snapshot=t243.inf",
		LAST);

	web_url("sezioni.css_6",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/sezioni.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_6}",
		"Snapshot=t244.inf",
		LAST);

	web_url("tabbedpage.css_6",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/tabbedpage.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_6}",
		"Snapshot=t245.inf",
		LAST);

	web_url("radioButton.css_6",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/radioButton.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_6}",
		"Snapshot=t246.inf",
		LAST);

	web_url("dropdown.css_6",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/dropdown.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_6}",
		"Snapshot=t247.inf",
		LAST);

	web_url("textarea.css_6",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/textarea.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_6}",
		"Snapshot=t248.inf",
		LAST);

	web_url("strategy.css_6",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/strategy.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_6}",
		"Snapshot=t249.inf",
		LAST);

	web_url("ff.css_6",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/ff.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_6}",
		"Snapshot=t250.inf",
		LAST);

	web_url("iframe.js_5",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/scripts/iframe.js?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_6}",
		"Snapshot=t251.inf",
		LAST);

	web_url("labelVariabili.css_6",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/labelVariabili.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_6}",
		"Snapshot=t252.inf",
		LAST);

	web_concurrent_end(NULL);

	web_concurrent_start(NULL);

	web_url("{JOB_3}_000002_SCZZOFPNST_03172016_X00000.PDF",
		"URL={zz00Protocol}://{zz00Ambiente}/FEEVO/{Username}/{Username}/{JOB_3}_{CorrelationParameter_1}.PDF",
		"Resource=1",
		"RecContentType=application/pdf",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_6}",
		"Snapshot=t253.inf",
		LAST);

	web_url("{JOB_3}_000002_SCZZOFPNST_03172016_X00000.PDF_2",
		"URL={zz00Protocol}://{zz00Ambiente}/FEEVO/{Username}/{Username}/{JOB_3}_{CorrelationParameter_1}.PDF",
		"Resource=1",
		"RecContentType=application/pdf",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_6}",
		"Snapshot=t254.inf",
		LAST);

	web_concurrent_end(NULL);

	web_add_auto_header("Pragma", 
		"no-cache");

	web_custom_request("FeestServlet_42",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t255.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=check~~jobnum={JOB_3}~~task=~~videata=~~id=~~attr=~~tipo=~~data=",
		LAST);

	web_url("{JOB_3}_000002_SCZZOFPNST_03172016_X00000.PDF_3",
		"URL={zz00Protocol}://{zz00Ambiente}/FEEVO/{Username}/{Username}/{JOB_3}_{CorrelationParameter_1}.PDF",
		"Resource=1",
		"RecContentType=application/pdf",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_6}",
		"Snapshot=t256.inf",
		LAST);

	/* esci */
	lr_end_transaction("11_StampaSecci", LR_AUTO);


	/* esci */

	lr_think_time(6);
	
	lr_start_transaction("12_EsciSecci");

	web_custom_request("FeestServlet_43",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t257.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=command~~jobnum={JOB_3}~~task=TK00000275~~videata=VisStampe~~id=BT00000004~~attr=mousedown~~tipo=~~data=",
		LAST);

	web_custom_request("FeestServlet_44",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t258.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=dynamicLoading~~jobnum={JOB_3}~~task=TK000005C8~~videata=VideoCalc~~id=GD0000017B~~attr=CARICAMENTO~~tipo=~~data=",
		LAST);

	web_custom_request("FeestServlet_45",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t259.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=dynamicLoading~~jobnum={JOB_3}~~task=TK000005C8~~videata=VideoCalc~~id=GD0000017F~~attr=CARICAMENTO~~tipo=~~data=",
		LAST);

	web_custom_request("FeestServlet_46",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t260.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=dynex~~jobnum={JOB_3}~~task=TK000005C8~~videata=VideoCalc~~id=~~attr=~~tipo=~~data=",
		LAST);

	/* conferma */
	lr_end_transaction("12_EsciSecci", LR_AUTO);

	/* conferma */

	lr_think_time(5);
	
	
	lr_start_transaction("13_Conferma");
	
		
	web_reg_save_param("TIMESTAMP_7",
		"LB=TIMESTAMP=",
		"RB='",
		LAST);
	

	web_custom_request("FeestServlet_47",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t261.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=command~~jobnum={JOB_3}~~task=TK000005C8~~videata=VideoCalc~~id=BT00000138~~attr=mousedown~~tipo=~~data=",
		LAST);

	web_revert_auto_header("Pragma");

	web_url("VideataServlet_6",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_7}",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t262.inf",
		"Mode=HTTP",
		LAST);

	web_concurrent_start(NULL);

	web_url("ocs.css_7",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/ocs.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_7}",
		"Snapshot=t263.inf",
		LAST);

	web_url("menu.css_7",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/menu.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_7}",
		"Snapshot=t264.inf",
		LAST);

	web_url("iframe.css_6",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/iframe.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_7}",
		"Snapshot=t265.inf",
		LAST);

	web_url("grid.css_7",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/grid.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_7}",
		"Snapshot=t266.inf",
		LAST);

	web_url("checkbox.css_7",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/checkbox.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_7}",
		"Snapshot=t267.inf",
		LAST);

	web_url("button.css_7",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/button.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_7}",
		"Snapshot=t268.inf",
		LAST);

	web_url("blocchi.css_7",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/blocchi.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_7}",
		"Snapshot=t269.inf",
		LAST);

	web_url("questionari.css_6",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/questionari.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_7}",
		"Snapshot=t270.inf",
		LAST);

	web_url("textfield.css_7",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/textfield.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_7}",
		"Snapshot=t271.inf",
		LAST);

	web_url("labelVariabili.css_7",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/labelVariabili.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_7}",
		"Snapshot=t272.inf",
		LAST);

	web_url("sezioni.css_7",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/sezioni.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_7}",
		"Snapshot=t273.inf",
		LAST);

	web_url("tabbedpage.css_7",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/tabbedpage.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_7}",
		"Snapshot=t274.inf",
		LAST);

	web_url("dropdown.css_7",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/dropdown.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_7}",
		"Snapshot=t275.inf",
		LAST);

	web_url("radioButton.css_7",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/radioButton.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_7}",
		"Snapshot=t276.inf",
		LAST);

	web_url("textarea.css_7",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/textarea.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_7}",
		"Snapshot=t277.inf",
		LAST);

	web_url("strategy.css_7",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/strategy.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_7}",
		"Snapshot=t278.inf",
		LAST);

	web_url("ff.css_7",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/ff.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_7}",
		"Snapshot=t279.inf",
		LAST);

	web_url("iframe.js_6",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/scripts/iframe.js?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_7}",
		"Snapshot=t280.inf",
		LAST);

	web_url("label.css_7",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/label.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_7}",
		"Snapshot=t281.inf",
		LAST);

	web_concurrent_end(NULL);

	web_url("visualizza_dettaglio.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/button/visualizza_dettaglio.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/button.css?p={p}",
		"Snapshot=t282.inf",
		LAST);

	web_add_auto_header("Pragma", 
		"no-cache");

	web_custom_request("FeestServlet_48",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t283.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=check~~jobnum={JOB}~~task=~~videata=~~id=~~attr=~~tipo=~~data=",
		LAST);

	web_custom_request("FeestServlet_49",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t284.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=replycheck",
		LAST);
	lr_end_transaction("13_Conferma", LR_AUTO);
	lr_think_time(5);
	
	lr_start_transaction("14_00_CompilazioneFormN2");



	/* statociv */

	

	lr_start_transaction("14_01_StatoCivile");

	web_custom_request("FeestServlet_50",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t285.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"BodyBinary=method=feestrequest~~azione=dynamicLoading~~jobnum={JOB}~~task=TK0000035F~~videata=Ana~~id=DD00000008~~attr=CONTROLLO~~tipo=P~~data=DD00000008$0\\xC2\\xA3%   \\xC2\\xA7DD00000008$1\\xC2\\xA3%{StatoCivile}",
		LAST);
	
	/* abitazione */
	lr_end_transaction("14_01_StatoCivile", LR_AUTO);

	
	lr_start_transaction("14_02_Abitazione");

	web_custom_request("FeestServlet_51",
		"URL={zz00Protocol}://{zz00Ambiente}/compass-demo/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/compass-demo/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t286.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"BodyBinary=method=feestrequest~~azione=dynamicLoading~~jobnum={JOB}~~task=TK0000035F~~videata=Ana~~id=DD00000010~~attr=CONTROLLO~~tipo=P~~data=DD00000010$0\\xC2\\xA3%   \\xC2\\xA7DD00000010$1\\xC2\\xA3%{Abitazione}",
		LAST);

	//lr_think_time(4);

	web_custom_request("FeestServlet_52",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t287.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=replycheck",
		LAST);


	lr_end_transaction("14_02_Abitazione", LR_AUTO);
	
	lr_start_transaction("14_03_Email");

	web_custom_request("FeestServlet_53",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t288.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=replycheck",
		LAST);

	/* email */

	//lr_think_time(29);

	web_custom_request("FeestServlet_54",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t289.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=replycheck",
		LAST);

	/* tipoatt */
	lr_end_transaction("14_03_Email", LR_AUTO);

	/* tipoatt */

	lr_think_time(5);
		lr_start_transaction("14_04_TipoAttivita");

	web_custom_request("FeestServlet_55",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t290.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"BodyBinary=method=feestrequest~~azione=pacchettoRichieste~~jobnum={JOB}~~data=(valorizzazione$&,$&{JOB}$&,$&TK0000035F$&,$&Ana$&,$&TF00000058$&,$&$&,$&TF00000058@\\xC2\\xA3%{AbitazioneDa}$&,$&)$,$(dynamicLoading$&,$&{JOB}$&,$&TK0000035F$&,$&Ana$&,$&DD00000013$&,$&CONTROLLO$&,$&DD00000013$0\\xC2\\xA3% \\xC2\\xA7DD00000013$1\\xC2\\xA3%{TipoAttivita}$&,$&P)",
		LAST);

	web_custom_request("FeestServlet_56",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t291.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=dynex~~jobnum={JOB}~~task=TK0000035F~~videata=Ana~~id=~~attr=~~tipo=~~data=",
		LAST);

				lr_end_transaction("14_04_TipoAttivita", LR_AUTO);
		
		lr_start_transaction("14_05_Settore");
		
	web_custom_request("FeestServlet_57",
		"URL={zz00Protocol}://{zz00Ambiente}/compass-demo/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/compass-demo/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t292.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"BodyBinary=method=feestrequest~~azione=dynamicLoading~~jobnum={JOB}~~task=TK0000035F~~videata=Ana~~id=DD00000014~~attr=CONTROLLO~~tipo=P~~data=DD00000014$0\\xC2\\xA3%   \\xC2\\xA7DD00000014$1\\xC2\\xA3%{SettoreAttivita}",
		LAST);



	web_custom_request("FeestServlet_58",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t293.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"BodyBinary=method=feestrequest~~azione=dynamicLoading~~jobnum={JOB}~~task=TK0000035F~~videata=Ana~~id=DD00000015~~attr=CONTROLLO~~tipo=P~~data=DD00000015$0\\xC2\\xA3%   \\xC2\\xA7DD00000015$1\\xC2\\xA3%{Occupazione}",
		LAST);



	web_custom_request("FeestServlet_59",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t294.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=replycheck",
		LAST);

	/* tipo reddito */

lr_end_transaction("14_05_Settore", LR_AUTO);

lr_start_transaction("14_06_TipoReddito");



	web_custom_request("FeestServlet_60",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t295.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"BodyBinary=method=feestrequest~~azione=pacchettoRichieste~~jobnum={JOB}~~data=(valorizzazione$&,$&{JOB}$&,$&TK0000035F$&,$&Ana$&,$&TF00000059$&,$&$&,$&TF00000059@\\xC2\\xA3%{OccupazioneDal}$&,$&)$,$(dynamicLoading$&,$&{JOB}$&,$&TK0000035F$&,$&Ana$&,$&DD00000017$&,$&CONTROLLO$&,$&DD00000017$0\\xC2\\xA3% \\xC2\\xA7DD00000017$1\\xC2\\xA3%{TipoReddito}$&,$&P)",
		LAST);



	web_custom_request("FeestServlet_61",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t296.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"BodyBinary=method=feestrequest~~azione=dynamicLoading~~jobnum={JOB}~~task=TK0000035F~~videata=Ana~~id=DD00000018~~attr=CONTROLLO~~tipo=P~~data=DD00000018$0\\xC2\\xA3%00\\xC2\\xA7DD00000018$1\\xC2\\xA3%{Mensilita}",
		LAST);



	web_custom_request("FeestServlet_62",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t297.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=replycheck",
		LAST);

	/* Familiari */
lr_end_transaction("14_06_TipoReddito", LR_AUTO);


lr_start_transaction("14_07_Familiari");

	web_custom_request("FeestServlet_63",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t298.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"BodyBinary=method=feestrequest~~azione=pacchettoRichieste~~jobnum={JOB}~~data=(valorizzazione$&,$&{JOB}$&,$&TK0000035F$&,$&Ana$&,$&TF00000108$&,$&$&,$&TF00000108@\\xC2\\xA3%{Reddito}$&,$&)$,$(dynamicLoading$&,$&{JOB}$&,$&TK0000035F$&,$&Ana$&,$&DD00000032$&,$&CONTROLLO$&,$&DD00000032$0\\xC2\\xA3%00\\xC2\\xA7DD00000032$1\\xC2\\xA3%{NumFamiliari}$&,$&P)",
		LAST);

	web_custom_request("FeestServlet_64",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t299.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"BodyBinary=method=feestrequest~~azione=dynamicLoading~~jobnum={JOB}~~task=TK0000035F~~videata=Ana~~id=DD00000033~~attr=CONTROLLO~~tipo=P~~data=DD00000033$0\\xC2\\xA3%00\\xC2\\xA7DD00000033$1\\xC2\\xA3%{NumFamiliariConReddito}",
		LAST);

		lr_end_transaction("14_07_Familiari", LR_AUTO);
lr_start_transaction("14_08_RapportoBP");

	web_custom_request("FeestServlet_65",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t300.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"BodyBinary=method=feestrequest~~azione=dynamicLoading~~jobnum={JOB}~~task=TK0000035F~~videata=Ana~~id=DD00000019~~attr=CONTROLLO~~tipo=P~~data=DD00000019$0\\xC2\\xA3%   \\xC2\\xA7DD00000019$1\\xC2\\xA3%{RapportoBancoPosta}",
		LAST);
	
	
	
		lr_end_transaction("14_08_RapportoBP", LR_AUTO);
	lr_end_transaction("14_00_CompilazioneFormN2", LR_AUTO);
lr_start_transaction("15_Prosegui");
			
	web_reg_save_param("TIMESTAMP_8",
		"LB=TIMESTAMP=",
		"RB='",
		LAST);

	web_custom_request("FeestServlet_66",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t301.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=command~~jobnum={JOB}~~task=TK0000035F~~videata=Ana~~id=BT0000003D~~attr=mousedown~~tipo=~~data=",
		LAST);

	web_revert_auto_header("Pragma");

	web_url("VideataServlet_7",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_8}",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t302.inf",
		"Mode=HTTP",
		LAST);

	web_concurrent_start(NULL);

	web_url("ocs.css_8",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/ocs.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_8}",
		"Snapshot=t303.inf",
		LAST);

	web_url("button.css_8",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/button.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_8}",
		"Snapshot=t304.inf",
		LAST);

	web_url("blocchi.css_8",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/blocchi.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_8}",
		"Snapshot=t305.inf",
		LAST);

	web_url("textfield.css_8",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/textfield.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_8}",
		"Snapshot=t306.inf",
		LAST);

	web_url("questionari.css_7",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/questionari.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_8}",
		"Snapshot=t307.inf",
		LAST);

	web_url("label.css_8",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/label.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_8}",
		"Snapshot=t308.inf",
		LAST);

	web_url("menu.css_8",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/menu.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_8}",
		"Snapshot=t309.inf",
		LAST);

	web_url("labelVariabili.css_8",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/labelVariabili.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_8}",
		"Snapshot=t310.inf",
		LAST);

	web_url("sezioni.css_8",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/sezioni.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_8}",
		"Snapshot=t311.inf",
		LAST);

	web_url("iframe.css_7",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/iframe.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_8}",
		"Snapshot=t312.inf",
		LAST);

	web_url("tabbedpage.css_8",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/tabbedpage.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_8}",
		"Snapshot=t313.inf",
		LAST);

	web_url("dropdown.css_8",
		"URL={zz00Protocol}://{zz00Ambiente}/compass-demo/ocint/dropdown.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/compass-demo/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_8}",
		"Snapshot=t314.inf",
		LAST);

	web_url("radioButton.css_8",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/radioButton.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_8}",
		"Snapshot=t315.inf",
		LAST);

	web_url("textarea.css_8",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/textarea.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_8}",
		"Snapshot=t316.inf",
		LAST);

	web_url("strategy.css_8",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/strategy.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_8}",
		"Snapshot=t317.inf",
		LAST);

	web_url("grid.css_8",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/grid.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_8}",
		"Snapshot=t318.inf",
		LAST);

	web_url("ff.css_8",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/ff.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_8}",
		"Snapshot=t319.inf",
		LAST);

	web_url("iframe.js_7",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/scripts/iframe.js?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_8}",
		"Snapshot=t320.inf",
		LAST);

	web_url("checkbox.css_8",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/checkbox.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_8}",
		"Snapshot=t321.inf",
		LAST);

	web_concurrent_end(NULL);

	web_url("calcola_decodifica.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/button/calcola_decodifica.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/button.css?p={p}",
		"Snapshot=t322.inf",
		LAST);

	web_add_auto_header("Pragma", 
		"no-cache");

	web_custom_request("FeestServlet_67",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t323.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=check~~jobnum={JOB}~~task=~~videata=~~id=~~attr=~~tipo=~~data=",
		LAST);


	web_custom_request("FeestServlet_68",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t324.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=replycheck",
		LAST);
	
	lr_end_transaction("15_Prosegui", LR_AUTO);
	
		lr_think_time(5);
lr_start_transaction("16_OrigineContratto");

	/* originecontratto */


	web_custom_request("FeestServlet_69",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t325.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"BodyBinary=method=feestrequest~~azione=dynamicLoading~~jobnum={JOB}~~task=TK00000041~~videata=DatiFinanziari~~id=DD00000041~~attr=CONTROLLO~~tipo=P~~data=DD00000041$0\\xC2\\xA3%   \\xC2\\xA7DD00000041$1\\xC2\\xA3%{OrigineContratto}",
		LAST);
lr_end_transaction("16_OrigineContratto", LR_AUTO);

	/* prosegui */

	lr_think_time(5);
	
	lr_start_transaction("17_Prosegui");

	web_custom_request("FeestServlet_70",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t326.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=command~~jobnum={JOB}~~task=TK00000041~~videata=DatiFinanziari~~id=BT0000003D~~attr=mousedown~~tipo=~~data=",
		LAST);

	web_custom_request("FeestServlet_71",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t327.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=dynamicLoading~~jobnum={JOB}~~task=TK00000041~~videata=DatiFinanziari~~id=GD0000001E~~attr=CARICAMENTO~~tipo=~~data=",
		LAST);

	web_custom_request("FeestServlet_72",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t328.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=dynex~~jobnum={JOB}~~task=TK00000041~~videata=DatiFinanziari~~id=~~attr=~~tipo=~~data=",
		LAST);

	web_custom_request("FeestServlet_73",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t329.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=replycheck",
		LAST);
	lr_end_transaction("17_Prosegui", LR_AUTO);


	/* prosegui */

	lr_think_time(5);
	lr_start_transaction("18_Prosegui");

	
		web_reg_save_param("TIMESTAMP_9",
		"LB=TIMESTAMP=",
		"RB='",
		LAST);

	web_custom_request("FeestServlet_74",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t330.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=command~~jobnum={JOB}~~task=TK00000041~~videata=DatiFinanziari~~id=BT0000003D~~attr=mousedown~~tipo=~~data=",
		LAST);

	web_revert_auto_header("Pragma");

	web_url("VideataServlet_8",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_9}",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t331.inf",
		"Mode=HTTP",
		LAST);

	web_concurrent_start(NULL);

	web_url("ocs.css_9",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/ocs.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_9}",
		"Snapshot=t332.inf",
		LAST);

	web_url("iframe.css_8",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/iframe.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_9}",
		"Snapshot=t333.inf",
		LAST);

	web_url("menu.css_9",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/menu.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_9}",
		"Snapshot=t334.inf",
		LAST);

	web_url("grid.css_9",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/grid.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_9}",
		"Snapshot=t335.inf",
		LAST);

	web_url("checkbox.css_9",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/checkbox.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_9}",
		"Snapshot=t336.inf",
		LAST);

	web_url("button.css_9",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/button.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_9}",
		"Snapshot=t337.inf",
		LAST);

	web_url("textfield.css_9",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/textfield.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_9}",
		"Snapshot=t338.inf",
		LAST);

	web_url("blocchi.css_9",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/blocchi.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_9}",
		"Snapshot=t339.inf",
		LAST);

	web_url("questionari.css_8",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/questionari.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_9}",
		"Snapshot=t340.inf",
		LAST);

	web_url("label.css_9",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/label.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_9}",
		"Snapshot=t341.inf",
		LAST);

	web_url("labelVariabili.css_9",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/labelVariabili.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_9}",
		"Snapshot=t342.inf",
		LAST);

	web_url("sezioni.css_9",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/sezioni.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_9}",
		"Snapshot=t343.inf",
		LAST);

	web_url("dropdown.css_9",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/dropdown.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_9}",
		"Snapshot=t344.inf",
		LAST);

	web_url("tabbedpage.css_9",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/tabbedpage.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_9}",
		"Snapshot=t345.inf",
		LAST);

	web_url("radioButton.css_9",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/radioButton.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_9}",
		"Snapshot=t346.inf",
		LAST);

	web_url("textarea.css_9",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/textarea.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_9}",
		"Snapshot=t347.inf",
		LAST);

	web_url("strategy.css_9",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/strategy.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_9}",
		"Snapshot=t348.inf",
		LAST);

	web_url("iframe.js_8",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/scripts/iframe.js?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_9}",
		"Snapshot=t349.inf",
		LAST);

	web_url("ff.css_9",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/ff.css?p={p}",
		"Resource=1",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/VideataServlet?progressivo=JVC0&TIMESTAMP={TIMESTAMP_9}",
		"Snapshot=t350.inf",
		LAST);

	web_concurrent_end(NULL);

	web_url("OCINT_operativita.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/button/OCINT_operativita.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/button.css?p={p}",
		"Snapshot=t351.inf",
		LAST);

	web_add_auto_header("Pragma", 
		"no-cache");

	web_custom_request("FeestServlet_75",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t352.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=check~~jobnum={JOB}~~task=~~videata=~~id=~~attr=~~tipo=~~data=",
		LAST);
lr_end_transaction("18_Prosegui", LR_AUTO);

	/* prosegui */

	lr_think_time(5);
	
	lr_start_transaction("19_Prosegui");

	web_custom_request("FeestServlet_76",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t353.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=replycheck",
		LAST);

	web_custom_request("FeestServlet_77",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t354.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=command~~jobnum={JOB}~~task=TK00000476~~videata=PostServizi~~id=BT0000003D~~attr=mousedown~~tipo=~~data=",
		LAST);

	web_custom_request("FeestServlet_78",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t355.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=dynamicLoading~~jobnum={JOB}~~task=TK000003B1~~videata=SchedaCli~~id=GD00000242~~attr=CARICAMENTO~~tipo=~~data=",
		LAST);

	web_custom_request("FeestServlet_79",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t356.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=dynamicLoading~~jobnum={JOB}~~task=TK000003B1~~videata=SchedaCli~~id=GD00000243~~attr=CARICAMENTO~~tipo=~~data=",
		LAST);

	web_custom_request("FeestServlet_80",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t357.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=dynex~~jobnum={JOB}~~task=TK000003B1~~videata=SchedaCli~~id=~~attr=~~tipo=~~data=",
		LAST);
	lr_end_transaction("19_Prosegui", LR_AUTO);


	/* esci */

	lr_think_time(6);
	lr_start_transaction("20_esci");


	web_custom_request("FeestServlet_81",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t358.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=command~~jobnum={JOB}~~task=TK000003B1~~videata=SchedaCli~~id=BT00000004~~attr=mousedown~~tipo=~~data=",
		LAST);

	web_custom_request("FeestServlet_82",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t359.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=dynex~~jobnum={JOB}~~task=TK000003B1~~videata=RicAna~~id=~~attr=~~tipo=~~data=",
		LAST);


	web_custom_request("FeestServlet_83",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t360.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=replycheck",
		LAST);
	lr_end_transaction("20_esci", LR_AUTO);


	/* logout */

lr_start_transaction("21_logout");

	web_custom_request("FeestServlet_84",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t361.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=replycheck",
		LAST);
	
	
			
			web_reg_save_param("JOB_END",
		"LB=warningQuit(\"Sei sicuro di voler uscire?\",\"si;no\",\"Y\",\"",
		"RB=\"",
		LAST);

	web_custom_request("FeestServlet_85",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t362.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=command~~jobnum= ~~task= ~~videata= ~~id=MIFEUTIL01~~attr=mousedown~~tipo=~~data=",
		LAST);

	web_url("OCINT_button_bg.png",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/button/OCINT_button_bg.png",
		"Resource=1",
		"RecContentType=image/png",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/button.css?p={p}",
		"Snapshot=t363.inf",
		LAST);

	/* si */
lr_end_transaction("21_logout", LR_AUTO);

	/* si */

	lr_think_time(5);
	
	lr_start_transaction("22_si");



	web_custom_request("FeestServlet_86",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t364.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=warningresponse~~jobnum={JOB_END}~~pulsante=si",
		LAST);

	

	
	web_custom_request("FeestServlet_87",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/FeestServlet",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/javascript",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t365.inf",
		"Mode=HTTP",
		"EncType=text/html; charset=UTF-8",
		"Body=method=feestrequest~~azione=check~~jobnum={JOB_END}~~task=~~videata=~~id=~~attr=~~tipo=~~data=",
		LAST);

	web_url("OCINT_3.gif",
		"URL={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/images/feest/window/OCINT_3.gif",
		"Resource=1",
		"RecContentType=image/gif",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/ocint/window.css?p={p}",
		"Snapshot=t366.inf",
		LAST);


	web_revert_auto_header("Pragma");

	web_url("{zz00LoginApp}_2",
		"URL={zz00Protocol}://{zz00Ambiente}/{zz00LoginApp}/",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={zz00Protocol}://{zz00Ambiente}/{URL_EVO}/feest/feest.jsp?TIMESTAMP={TIMESTAMP}",
		"Snapshot=t367.inf",
		"Mode=HTTP",
		LAST);
lr_end_transaction("22_si", LR_AUTO);

lr_end_transaction("00_Global", LR_AUTO);

	return 0;
}