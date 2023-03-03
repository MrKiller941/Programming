class componentRouter  {
    
   constructor(root) { 
	  this._root = root;
      this._default = ''; 
      this._routes = [];       
   }
         
   add(url,view) {
      this._routes.push({'url':url,'view':view}); 
   }
 
   
   default(url) {
      this._default = url;  
   }
   
   
   async go(url='') {
       
     let view = null;
     
     if (url==='') {
       url = this._default;  
     }
     
     this._routes.forEach(route => {
        if (route.url === url) {
           view = route.view;  
        } 
     });
     
     
     if (view!==null) {        
        await import('./../components/page_cmp/'+view+'/'+view+'.js');
        let nodeView =  document.createElement(view);
        		
     	while (this._root.firstChild) {
    		 this._root.removeChild(this._root.firstChild);
		}
		
        this._root.appendChild(nodeView); 
        history.pushState(null,null,url);
     }   
        
        
   }
   
}


class RouterFactory {
   
   static _router = null;
   
   static _createInstance(rootNode) {
     return new componentRouter(rootNode);      
   }
      
   static createInstance(rootNode) {
      if (RouterFactory._router === null) {
        RouterFactory._router = RouterFactory._createInstance(rootNode);  
      }      
      return RouterFactory._router;
   }
}


export {RouterFactory};