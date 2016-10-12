<?php
$session = array();
$cookie = array();
$cookie['sessionid'] = '47cSrd8cBRXOrBhYQT1ptPOt8hugu3qMSzXtJ1LY6wGNR0PNLE196DSAlHEJmkYj';
$get = array();
$post = array();
$define = array();
$define['form-crsf'] = 'une erreur est survenue pendant la validation du formulaire';
$define['promotion-year'] = '2013';
$define['user-admin'] = 'ADMIN';
$define['user-student'] = 'STUDENT';
$define['user-teacher'] = 'TEACHER';
$request = array();
$request['action'] = 'login';
$request['controller'] = 'user';
$request['logged'] = '0';
$request['name'] = 'user-login';
$request['url'] = '/';
$title = 'Connexion';
?><!DOCTYPE html>
<html style="opacity:0;">
	<head>
		<meta charset="utf-8" />
		<title><?php echo $title; ?> - GestNotes</title>
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
					<div id="login-top"><?php echo $title; ?></div> 
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
