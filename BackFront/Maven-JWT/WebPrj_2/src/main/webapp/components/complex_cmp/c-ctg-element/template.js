
export default function(cls) {return `
	<style>
		.container{
			border: solid;
			border-color: #888;
  			border-width: 2px;
  			width:  30vw;
  			height:  16vw;
  			margin: 15px 30% 15px;
  			background-color: #999;
  			border-radius: 6px;
  			font-family: "Inter UI","SF Pro Display",-apple-system,BlinkMacSystemFont,"Segoe UI",Roboto,Oxygen,Ubuntu,Cantarell,"Open Sans","Helvetica Neue",sans-serif;
		}
		
		.name{
			position: relative;
			font-size: 3vw;
			top: 0vw;
			left: 1vw;
		}

		.cost{
			position: relative;
			font-size: 2vw;
			left: 1vw;
			top: -10.1vw;
		}
	
		img{
			position: relative;
			left: 16vw;
			bottom: 8.5vw;
			border: solid;
			border-color: #7cabf2;
  			border-width: 1px;
  			border-radius: 10px;
  			width: 40%;
  			height: 60%;
  			top: 0vw;
		}

		.desc{ position: relative;
			font-size: 2vw;
			left: 1vw;
			bottom: 5vw;
			width: 25vw;
			top: -13vw;
		}
		
		c-button{ 
			position: relative;
			left: 1vw;
			top: -3.5vw;
			width: 9vw;
			height: 4vw;
		}
		
	</style>
	
  	<div class="container">
  		<div 		class="name"									  	>${cls._name}		</div>
  		<img 	 	src=${cls._src}  width="200" height="100"		  	>			   		</img>
    	<div 		class="cost" 	 								  	>${cls._cost} руб 	</div>
    	<c-button  	class="buyBt"	 value="Купить"	id=${cls._prod_id}  >			   		</c-button>
    	<div 		class="desc" 	 								  	>${cls._desc} штук	</div>
    </div>
`}