<?php
$session = array();
$session['avatar'] = '/public/img/user.png';
$session['email'] = 'willima.stow@efrei.net';
$session['firstname'] = 'William';
$session['id'] = 'admin1';
$session['logged'] = '1';
$session['name'] = 'Stow';
$session['role'] = 'ADMIN';
$session['token'] = '703a4502e589c4c25b96d9f20c31f76f9e978606';
$cookie = array();
$cookie['sessionid'] = '49KIWl8z1DRxb80FPTDb6rOw42FsHiaWfDqZFrtuwVSLpvHhe7sj09KaRaAYIB37';
$get = array();
$get['token'] = '703a4502e589c4c25b96d9f20c31f76f9e978606';
$post = array();
$define = array();
$define['form-crsf'] = 'une erreur est survenue pendant la validation du formulaire';
$define['promotion-year'] = '2013';
$define['user-admin'] = 'ADMIN';
$define['user-student'] = 'STUDENT';
$define['user-teacher'] = 'TEACHER';
$request = array();
$request['action'] = 'newTeacher';
$request['controller'] = 'adminTeacher';
$request['logged'] = '1';
$request['name'] = 'admin-teacher-new';
$request['url'] = '/admin/teacher/new/(.*)(/*)';
$title = 'Nouveau professeur';
$filAriane = 'Professeur/Nouveau professeur';
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



			


<?php
	$name = (isset($post["name"])) ? $post["name"] : "";
	$firstname = (isset($post["firstname"])) ? $post["firstname"] : "";
	$email = (isset($post["email"])) ? $post["email"] : "";
	$address = (isset($post["address"])) ? $post["address"] : "";
	$postalCode = (isset($post["postalCode"])) ? $post["postalCode"] : "";
	$city = (isset($post["city"])) ? $post["city"] : "";
	$country = (isset($post["country"])) ? $post["country"] : "";
	$phoneHome = (isset($post["phone-home"])) ? $post["phone-home"] : "";
	$phoneMobile = (isset($post["phone-mobile"])) ? $post["phone-mobile"] : "";
	$dateBorn = (isset($post["date-born"])) ? $post["date-born"] : "";
	$gender = (isset($post["gender"])) ? $post["gender"] : "0";
?>

<form method="post" action="">
	<label>Nom</label><input type="text" name="name" value="<?php echo $name; ?>"/><br />
	<label>Prénom</label><input type="text" name="firstname" value="<?php echo $firstname; ?>"/><br />
	<label>Email</label><input type="text" name="email" value="<?php echo $email; ?>"/><br />
	<label>Adresse</label><input type="text" name="address" value="<?php echo $address; ?>"/><br />
	<label>Code postal</label><input type="number" name="postalCode" value="<?php echo $postalCode; ?>"/><br />
	<label>Ville</label><input type="text" name="city" value="<?php echo $city; ?>"/><br />
	<label>Pays</label><input type="text" name="country" value="<?php echo $country; ?>"/><br />
	<label>Téléphone fixe</label><input type="text" name="phone-home" value="<?php echo $phoneHome; ?>"/><br />
	<label>Téléphone mobile</label><input type="text" name="phone-mobile" value="<?php echo $phoneMobile; ?>"/><br />
	<label>Date de naissance</label><input type="text" name="date-born" value="<?php echo $dateBorn; ?>"/><br />
	<label>Sexe</label>
	<select name="gender">
		<option value="0" <?php if($gender == '0'){ ?>selected<?php } ?>>Homme</option>
		<option value="1" <?php if($gender == '1'){ ?>selected<?php } ?>>Femme</option>
	</select><br />
	<input type="hidden" name="token" value="<?php echo $session['token']; ?>" />
	<input type="submit" value="Enregistrer" />
</form>

<?php
?>		</div>
		<footer></footer>	
	</body>
</html>

