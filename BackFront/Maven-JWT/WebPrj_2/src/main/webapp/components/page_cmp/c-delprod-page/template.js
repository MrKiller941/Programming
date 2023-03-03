export default function(func) {return `
	<style>
	
		.panel{
			position: absolute;
			margin-left: 40%;
			margin-top: 65px;
			list-style-type: none;
		}
		
	</style>
	
	<ul class="panel">
		<li class="nm"    >Название:<br>				<c-textbar class="name">				</c-textbar></li>
		<li class="bt"	  >								<c-button value="Отправить">			</c-button></li>
		<li class="btBack">								<c-button value="Назад">				</c-button></li>
		<div class="message">																	</div>
	</ul>            
`}