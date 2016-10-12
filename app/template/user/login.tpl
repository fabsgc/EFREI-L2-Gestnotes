<!DOCTYPE html>
<html style="opacity:0;">
	<head>
		<meta charset="utf-8" />
		<title>{$title} - GestNotes</title>
		<link rel="icon" type="image/png" href="/public/img/icon.png" />
		<link href="/public/css/login.css" rel="stylesheet" media="screen" type="text/css" /> 
		<link href="/public/file/font-awesome/css/font-awesome.min.css" rel="stylesheet" media="screen" type="text/css" />
		<script type="text/javascript" src="public/js/jquery-1.11.2.min.js"></script>
		<script type="text/javascript" src="public/js/login.js"></script>
	</head>
	<body id="body"> 
		<div id="main-login"> 
			<header class="login"> 
				<div id="logo"> 
					<i class="fa fa-book"></i> GestNotes
				</div> 
			</header> 
			<div id="login" class="stack twisted"> 
				<div class="content"> 
					<div id="login-top">{$title}</div> 
					<div id="login-content"> 
						<input type="text" id="username" placeholder="Nom d'utilisateur"/> 
						<input type="password" id="password" placeholder="Mot de passe"/> 
						<input type="button" id="send" value="Se connecter"/> 
						<div id="error"></div> 
					</div> 
				</div> 
			</div> 
		</div>
	</body>
</html>