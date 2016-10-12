<?php
$session = array();
$session['avatar'] = '/public/img/user.png';
$session['email'] = 'willima.stow@efrei.net';
$session['firstname'] = 'William';
$session['id'] = 'admin1';
$session['logged'] = '1';
$session['name'] = 'Stow';
$session['role'] = 'ADMIN';
$session['token'] = 'b47d6c855ec82ce4451ecc2e4ceae4dc3fc9f0c8';
$cookie = array();
$cookie['sessionid'] = 'P89M4hzsnl1F2bmUPIqWZnUnslh7zZUxzRhQ1yhbzBopzKNrVtDbcnQdtem1us8S';
$get = array();
$get['id'] = 'teacher2';
$post = array();
$define = array();
$define['form-crsf'] = 'une erreur est survenue pendant la validation du formulaire';
$define['promotion-year'] = '2013';
$define['user-admin'] = 'ADMIN';
$define['user-student'] = 'STUDENT';
$define['user-teacher'] = 'TEACHER';
$request = array();
$request['action'] = 'seeTeacher';
$request['controller'] = 'adminTeacher';
$request['logged'] = '1';
$request['name'] = 'admin-teacher-see';
$request['url'] = '/admin/teacher/see/([a-z0-9]+)(/*)';
$title = 'Georges - Teller';
$filAriane = 'Professeur/Georges - Teller';
$teacher = array(); 
$teacher['id'] = 'teacher2';
$teacher['password'] = '61b115da227a57859490c53251490fffe66c6d67';
$teacher['personDetail'] = array(); 
$teacher['personDetail']['id'] = 11;
$teacher['personDetail']['name'] = 'Teller';
$teacher['personDetail']['firstName'] = 'Georges';
$teacher['personDetail']['address'] = '5 rue du marin';
$teacher['personDetail']['city'] = 'Sceaux';
$teacher['personDetail']['postalCode'] = '92000';
$teacher['personDetail']['country'] = 'France';
$teacher['personDetail']['email'] = 'g.teller@yahoo.fr';
$teacher['personDetail']['avatar'] = '/public/img/avatar.png';
$teacher['personDetail']['phoneHome'] = '0123456789';
$teacher['personDetail']['phoneMobile'] = '0654734589';
$teacher['personDetail']['dateBorn'] = '23/04/1955';
$teacher['personDetail']['dateRegister'] = '';
$teacher['personDetail']['gender'] = 0;
?><?php
?><!DOCTYPE html>
<html style="opacity:0;">
	<head>
		<meta charset="utf-8" />
		<title><?php echo $title; ?> - GestNotes</title>
		<link rel="icon" type="image/png" href="/public/img/icon.png" />
		<link href="/public/css/default.css" rel="stylesheet" media="screen" type="text/css" /> 
		<link href="/public/file/font-awesome/css/font-awesome.min.css" rel="stylesheet" media="screen" type="text/css" />
		<script type="text/javascript" src="/public/js/jquery-1.11.2.min.js"></script>
		<script type="text/javascript" src="/public/js/default.js"></script>
	</head>
	<body id="body">
		<header class="default">
			<div id="header-left">
				<i class="fa fa-book"></i> GestNotes
			</div>
			<div id="header-right">
				<div class="right-account">
					<div id="logout" class="account-logout">
						<i class="fa fa-sign-out"></i>
					</div>
					<div class="account-profile">
						<div class="profile-username">
							<?php echo $session['firstname']; ?> - <?php echo $session['name']; ?>
						</div>
						<div class="profile-avatar">
							<img src="<?php echo $session['avatar']; ?>"/>
						</div>
					</div>
				</div>
			</div>
			<div class="clear"/>
		</header>
		<div id="side-menu">
			<ul>
				<li <?php if($request['controller'] == 'index'){ ?>class="active"<?php } ?>>
					<a href="/">
						<i class="fa fa-home"></i>
						<span class="title">Accueil</class>
					</a>
				</li>
				<li <?php if($request['controller'] == 'user'){ ?>class="active"<?php } ?>>
					<a href="/user">
						<i class="fa fa-user"></i>
						<span class="title">Profil</class>
					</a>
				</li>
				<?php if($session['role'] == $define['user-student']){ ?>
					<li <?php if($request['controller'] == 'studentMark'){ ?>class="active"<?php } ?>>
						<a href="/student/mark">
							<i class="fa fa-university"></i>
							<span class="title">Notes</class>
						</a>
					</li>
					<li <?php if($request['controller'] == 'studentCourse'){ ?>class="active"<?php } ?>>
						<a href="/student/course">
							<i class="fa fa-folder-open"></i>
							<span class="title">Cours</class>
						</a>
					</li>
				<?php } ?>
				<?php if($session['role'] == $define['user-teacher']){ ?>
					<li <?php if($request['controller'] == 'teacherMark'){ ?>class="active"<?php } ?>>
						<a href="/teacher/mark">
							<i class="fa fa-university"></i>
							<span class="title">Notes</class>
						</a>
					</li>
					<li <?php if($request['controller'] == 'teacherCourse'){ ?>class="active"<?php } ?>>
						<a href="/teacher/course">
							<i class="fa fa-folder-open"></i>
							<span class="title">Cours</class>
						</a>
					</li>
					<li <?php if($request['controller'] == 'teacherStudent'){ ?>class="active"<?php } ?>>
						<a href="/teacher/student">
							<i class="fa fa-users"></i>
							<span class="title">Élèves</class>
						</a>
					</li>
				<?php } ?>
				<?php if($session['role'] == $define['user-admin']){ ?>
					<li <?php if($request['controller'] == 'adminStudent'){ ?>class="active"<?php } ?>>
						<a href="/admin/student">
							<i class="fa fa-user-plus"></i>
							<span class="title">Élèves</class>
						</a>
					</li>
					<li <?php if($request['controller'] == 'adminTeacher'){ ?>class="active"<?php } ?>>
						<a href="/admin/teacher">
							<i class="fa fa-binoculars"></i>
							<span class="title">Professeurs</class>
						</a>
					</li>
					<li <?php if($request['controller'] == 'adminGroup'){ ?>class="active"<?php } ?>>
						<a href="/admin/group">
							<i class="fa fa-users"></i>
							<span class="title">Groupes</class>
						</a>
					</li>
					<li <?php if($request['controller'] == 'adminCourse'){ ?>class="active"<?php } ?>>
						<a href="/admin/course">
							<i class="fa fa-folder-open"></i>
							<span class="title">Cours</class>
						</a>
					</li>
					<li <?php if($request['controller'] == 'adminMark'){ ?>class="active"<?php } ?>>
						<a href="/admin/mark">
							<i class="fa fa-university"></i>
							<span class="title">Notes</class>
						</a>
					</li>
				<?php } ?>
			</ul>
		</div>
		<div id="main">
			<?php if($request['controller'] != 'index'){ ?>
				<h2><?php echo $title; ?></h2>
			<?php } ?>
			<div id="fil-ariane">
				<ul>
					<?php
						if(isset($filAriane))
						{
							$filAriane = explode('/', 'Accueil/'.$filAriane);
						}
						else
						{
							$filAriane = array('Accueil');
						}
					?>
					<?php foreach($filAriane as $key => $value){ ?>
						<li>
							<?php echo $value; ?>
						</li>
						<?php if(count($filAriane) > 1 && $key < count($filAriane)-1){ ?>
							<span class="fa fa-chevron-right">&#160;</span>
						<?php } ?>
					<?php } ?>
				</ul>
			</div>
			<?php
?><?php if(isset($formErrors) && count($formErrors) > 0){ ?>
	<div class="alert alert-error">
		<?php foreach($formErrors as $key => $errors){ ?>
			<?php foreach($errors as $key2 => $error){ ?>
				<?php echo $error; ?>
				<?php if(count($errors) > $key2 + 1){ ?>
					<br />
				<?php } ?>
			<?php } ?>
			<?php if(count($formErrors) > $key + 1){ ?>
				<br />
			<?php } ?>
		<?php } ?>
	</div>	
<?php } ?>
<?php if(isset($session['flash_success'])){ ?>
	<div class="alert alert-success">
		<div class="close" onclick="closeFlashMessage(this);"><span class="fa fa-times">&nbsp;</span> </div>
		<?php echo $session['flash_success']; ?>
	</div>
<?php } ?>



			

<ul>
	<li><strong>Nom</strong> : <?php echo $teacher['personDetail']['name']; ?></li>
	<li><strong>Prénom</strong> : <?php echo $teacher['personDetail']['firstName']; ?></li>
	<li><strong>Email</strong> : <?php echo $teacher['personDetail']['email']; ?></li>
	<li><strong>Adresse</strong> : <?php echo $teacher['personDetail']['address']; ?></li>
	<li><strong>Code postal</strong> : <?php echo $teacher['personDetail']['postalCode']; ?></li>
	<li><strong>Ville</strong> : <?php echo $teacher['personDetail']['city']; ?></li>
	<li><strong>Pays</strong> : <?php echo $teacher['personDetail']['country']; ?></li>
	<li><strong>Téléphone fixe</strong> : <?php echo $teacher['personDetail']['phoneHome']; ?></li>
	<li><strong>Téléphone mobile</strong> : <?php echo $teacher['personDetail']['phoneMobile']; ?></li>
	<li><strong>Date de naissance</strong> : <?php echo $teacher['personDetail']['dateBorn']; ?></li>
	<li>
		<strong>Sexe</strong> :
		<?php if($teacher['personDetail']['gender'] == '0'){ ?>
			homme
		<?php } else { ?>
			femme
		<?php } ?>
	</li>
</ul>
<?php
?>		</div>
		<footer></footer>	
	</body>
</html>

