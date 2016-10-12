<?php
$session = array();
$session['avatar'] = '/public/img/user.png';
$session['email'] = 'willima.stow@efrei.net';
$session['firstname'] = 'William';
$session['id'] = 'admin1';
$session['logged'] = '1';
$session['name'] = 'Stow';
$session['role'] = 'ADMIN';
$session['token'] = '3364ad63e86ef2850b81e02f54891bd0f1abc7fd';
$cookie = array();
$cookie['sessionid'] = 'oqEJfzkZQIvqHuEWyONKD8R2lvg41TEXpxvpMSNN2mVWWJWc5UOyYVNUlGxGxFip';
$get = array();
$get['id'] = '20130089';
$post = array();
$define = array();
$define['form-crsf'] = 'une erreur est survenue pendant la validation du formulaire';
$define['promotion-year'] = '2013';
$define['user-admin'] = 'ADMIN';
$define['user-student'] = 'STUDENT';
$define['user-teacher'] = 'TEACHER';
$request = array();
$request['action'] = 'seeStudent';
$request['controller'] = 'adminStudent';
$request['logged'] = '1';
$request['name'] = 'admin-student-see';
$request['url'] = '/admin/student/see/([0-9]+)(/*)';
$title = 'Fabien - Beaujean';
$filAriane = 'Élèves/Fabien - Beaujean';
$student = array(); 
$student['id'] = '20130089';
$student['password'] = '61b115da227a57859490c53251490fffe66c6d67';
$student['sucessYear'] = false;
$student['group'] = 4;
$student['personDetail'] = array(); 
$student['personDetail']['id'] = 1;
$student['personDetail']['name'] = 'Beaujean';
$student['personDetail']['firstName'] = 'Fabien';
$student['personDetail']['address'] = '1 allée des mûriers';
$student['personDetail']['city'] = 'Verrières-le-Buisson';
$student['personDetail']['postalCode'] = '91370';
$student['personDetail']['country'] = 'France';
$student['personDetail']['email'] = 'fabien.beaujean@efrei.net';
$student['personDetail']['avatar'] = '/public/img/avatar.png';
$student['personDetail']['phoneHome'] = '0169307310';
$student['personDetail']['phoneMobile'] = '0786027310';
$student['personDetail']['dateBorn'] = '20/07/1995';
$student['personDetail']['dateRegister'] = '';
$student['personDetail']['gender'] = 0;
$student['contact'] = array(); 
$student['contact']['id'] = '1';
$student['contact']['personDetail'] = array(); 
$student['contact']['personDetail']['id'] = 3;
$student['contact']['personDetail']['name'] = 'Beaujean';
$student['contact']['personDetail']['firstName'] = 'Franck';
$student['contact']['personDetail']['address'] = '1 allée des mûriers';
$student['contact']['personDetail']['city'] = 'Verrières-le-Buisson';
$student['contact']['personDetail']['postalCode'] = '91370';
$student['contact']['personDetail']['country'] = 'France';
$student['contact']['personDetail']['email'] = 'franck.beaujean@yahoo.fr';
$student['contact']['personDetail']['avatar'] = '/public/img/user.png';
$student['contact']['personDetail']['phoneHome'] = '';
$student['contact']['personDetail']['phoneMobile'] = '';
$student['contact']['personDetail']['dateBorn'] = '';
$student['contact']['personDetail']['dateRegister'] = '';
$student['contact']['personDetail']['gender'] = 0;
$student['teacher'] = array(); 
$student['teacher']['id'] = 'teacher1';
$student['teacher']['password'] = '61b115da227a57859490c53251490fffe66c6d67';
$student['teacher']['personDetail'] = array(); 
$student['teacher']['personDetail']['id'] = 2;
$student['teacher']['personDetail']['name'] = 'Lepoivre';
$student['teacher']['personDetail']['firstName'] = 'Franck';
$student['teacher']['personDetail']['address'] = '1 allée des mûriers';
$student['teacher']['personDetail']['city'] = 'paris';
$student['teacher']['personDetail']['postalCode'] = '75008';
$student['teacher']['personDetail']['country'] = 'France';
$student['teacher']['personDetail']['email'] = 'franck.lepoivre@gmail.com';
$student['teacher']['personDetail']['avatar'] = '/public/img/user.png';
$student['teacher']['personDetail']['phoneHome'] = '0189567854';
$student['teacher']['personDetail']['phoneMobile'] = '0645732409';
$student['teacher']['personDetail']['dateBorn'] = '20/09/1965';
$student['teacher']['personDetail']['dateRegister'] = '';
$student['teacher']['personDetail']['gender'] = 0;
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



			


<a href="/admin/student/report/generate/<?php echo $student['id']; ?>/<?php echo $session['token']; ?>" class="button right">Editer le bulletin de l'élève</a>
<div class="clear-right"></div>
<h4>Elève</h4>
<ul>
	<li><strong>Nom</strong> : <?php echo $student['personDetail']['name']; ?></li>
	<li><strong>Prénom</strong> : <?php echo $student['personDetail']['firstName']; ?></li>
	<li><strong>Email</strong> : <?php echo $student['personDetail']['email']; ?></li>
	<li><strong>Adresse</strong> : <?php echo $student['personDetail']['address']; ?></li>
	<li><strong>Code postal</strong> : <?php echo $student['personDetail']['postalCode']; ?></li>
	<li><strong>Ville</strong> : <?php echo $student['personDetail']['city']; ?></li>
	<li><strong>Pays</strong> : <?php echo $student['personDetail']['country']; ?></li>
	<li><strong>Téléphone fixe</strong> : <?php echo $student['personDetail']['phoneHome']; ?></li>
	<li><strong>Téléphone mobile</strong> : <?php echo $student['personDetail']['phoneMobile']; ?></li>
	<li><strong>Date de naissance</strong> : <?php echo $student['personDetail']['dateBorn']; ?></li>
	<li>
		<strong>Sexe</strong> :
		<?php if($student['personDetail']['gender'] == '0'){ ?>
			homme
		<?php } else { ?>
			femme
		<?php } ?>
	</li>
	<li>
		<strong>Professeur référent</strong> : 
		<?php echo $student['teacher']['personDetail']['firstName']; ?>  
		<?php echo $student['teacher']['personDetail']['name']; ?>
	</li>
</ul>
<h4>Responsable</h4>
<ul>
	<li><strong>Nom</strong> : <?php echo $student['contact']['personDetail']['name']; ?></li>
	<li><strong>Prénom</strong> : <?php echo $student['contact']['personDetail']['firstName']; ?></li>
	<li><strong>Email</strong> : <?php echo $student['contact']['personDetail']['email']; ?></li>
	<li><strong>Adresse</strong> : <?php echo $student['contact']['personDetail']['address']; ?></li>
	<li><strong>Code postal</strong> : <?php echo $student['contact']['personDetail']['postalCode']; ?></li>
	<li><strong>Ville</strong> : <?php echo $student['contact']['personDetail']['city']; ?></li>
	<li><strong>Pays</strong> : <?php echo $student['contact']['personDetail']['country']; ?></li>
	<li><strong>Téléphone fixe</strong> : <?php echo $student['contact']['personDetail']['phoneHome']; ?></li>
	<li><strong>Téléphone mobile</strong> : <?php echo $student['contact']['personDetail']['phoneMobile']; ?></li>
	<li>
		<strong>Sexe</strong> :
		<?php if($student['contact']['personDetail']['gender'] == '0'){ ?>
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

