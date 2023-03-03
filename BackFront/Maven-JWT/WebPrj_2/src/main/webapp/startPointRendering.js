(async ()=>{ await true;
	let root = document.getElementById('root_point');
	
	
	let routerModule = await import('./componentRouter/componentRouter.js');
	let router = routerModule.RouterFactory.createInstance(root);


	router.add('c-log-page',    	'c-log-page');
	router.add('c-reg-page',  	  	'c-reg-page');
	router.add('c-catalog-page',  	'c-catalog-page');
	router.add('c-addprod-page',  	'c-addprod-page');
	router.add('c-delprod-page',  	'c-delprod-page');
	
	router.default('c-log-page');
	router.go();
})();