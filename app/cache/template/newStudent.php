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
$get['token'] = '3364ad63e86ef2850b81e02f54891bd0f1abc7fd';
$post = array();
$define = array();
$define['form-crsf'] = 'une erreur est survenue pendant la validation du formulaire';
$define['promotion-year'] = '2013';
$define['user-admin'] = 'ADMIN';
$define['user-student'] = 'STUDENT';
$define['user-teacher'] = 'TEACHER';
$request = array();
$request['action'] = 'newStudent';
$request['controller'] = 'adminStudent';
$request['logged'] = '1';
$request['name'] = 'admin-student-new';
$request['url'] = '/admin/student/new/(.*)(/*)';
$title = 'Nouvel élève';
$filAriane = 'Élèves/Nouvel élève';
$contacts = array(); 
$contacts['0'] = array(); 
$contacts['0']['id'] = '3';
$contacts['0']['personDetail'] = array(); 
$contacts['0']['personDetail']['id'] = 7;
$contacts['0']['personDetail']['name'] = 'Lorentz';
$contacts['0']['personDetail']['firstName'] = 'Papa';
$contacts['0']['personDetail']['address'] = '34 avenue de la charette';
$contacts['0']['personDetail']['city'] = 'Versailles';
$contacts['0']['personDetail']['postalCode'] = '78007';
$contacts['0']['personDetail']['country'] = 'France';
$contacts['0']['personDetail']['email'] = 'papa.lorentz@yahoo.fr';
$contacts['0']['personDetail']['avatar'] = '';
$contacts['0']['personDetail']['phoneHome'] = '0189567854';
$contacts['0']['personDetail']['phoneMobile'] = '0680567854';
$contacts['0']['personDetail']['dateBorn'] = '';
$contacts['0']['personDetail']['dateRegister'] = '';
$contacts['0']['personDetail']['gender'] = 0;
$contacts['1'] = array(); 
$contacts['1']['id'] = '1';
$contacts['1']['personDetail'] = array(); 
$contacts['1']['personDetail']['id'] = 3;
$contacts['1']['personDetail']['name'] = 'Beaujean';
$contacts['1']['personDetail']['firstName'] = 'Franck';
$contacts['1']['personDetail']['address'] = '1 allée des mûriers';
$contacts['1']['personDetail']['city'] = 'Verrières-le-Buisson';
$contacts['1']['personDetail']['postalCode'] = '91370';
$contacts['1']['personDetail']['country'] = 'France';
$contacts['1']['personDetail']['email'] = 'franck.beaujean@yahoo.fr';
$contacts['1']['personDetail']['avatar'] = '/public/img/user.png';
$contacts['1']['personDetail']['phoneHome'] = '';
$contacts['1']['personDetail']['phoneMobile'] = '';
$contacts['1']['personDetail']['dateBorn'] = '';
$contacts['1']['personDetail']['dateRegister'] = '';
$contacts['1']['personDetail']['gender'] = 0;
$teachers = array(); 
$teachers['0'] = array(); 
$teachers['0']['id'] = 'teacher2';
$teachers['0']['password'] = '61b115da227a57859490c53251490fffe66c6d67';
$teachers['0']['personDetail'] = array(); 
$teachers['0']['personDetail']['id'] = 11;
$teachers['0']['personDetail']['name'] = 'Teller';
$teachers['0']['personDetail']['firstName'] = 'Georges';
$teachers['0']['personDetail']['address'] = '5 rue du marin';
$teachers['0']['personDetail']['city'] = 'Sceaux';
$teachers['0']['personDetail']['postalCode'] = '92000';
$teachers['0']['personDetail']['country'] = 'France';
$teachers['0']['personDetail']['email'] = 'g.teller@yahoo.fr';
$teachers['0']['personDetail']['avatar'] = '/public/img/avatar.png';
$teachers['0']['personDetail']['phoneHome'] = '0123456789';
$teachers['0']['personDetail']['phoneMobile'] = '0654734589';
$teachers['0']['personDetail']['dateBorn'] = '23/04/1955';
$teachers['0']['personDetail']['dateRegister'] = '';
$teachers['0']['personDetail']['gender'] = 0;
$teachers['1'] = array(); 
$teachers['1']['id'] = 'teacher1';
$teachers['1']['password'] = '61b115da227a57859490c53251490fffe66c6d67';
$teachers['1']['personDetail'] = array(); 
$teachers['1']['personDetail']['id'] = 2;
$teachers['1']['personDetail']['name'] = 'Lepoivre';
$teachers['1']['personDetail']['firstName'] = 'Franck';
$teachers['1']['personDetail']['address'] = '1 allée des mûriers';
$teachers['1']['personDetail']['city'] = 'paris';
$teachers['1']['personDetail']['postalCode'] = '75008';
$teachers['1']['personDetail']['country'] = 'France';
$teachers['1']['personDetail']['email'] = 'franck.lepoivre@gmail.com';
$teachers['1']['personDetail']['avatar'] = '/public/img/user.png';
$teachers['1']['personDetail']['phoneHome'] = '0189567854';
$teachers['1']['personDetail']['phoneMobile'] = '0645732409';
$teachers['1']['personDetail']['dateBorn'] = '20/09/1965';
$teachers['1']['personDetail']['dateRegister'] = '';
$teachers['1']['personDetail']['gender'] = 0;
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
	$teacher = (isset($post["teaher"])) ? $post["teacher"] : "";
	$contact = (isset($post["contact"])) ? $post["contact"] : "0";

	$contactName = (isset($post["contact-name"])) ? $post["contact-name"] : "";
	$contactFirstname = (isset($post["contact-firstname"])) ? $post["contact-firstname"] : "";
	$contactEmail = (isset($post["contact-email"])) ? $post["contact-email"] : "";
	$contactAddress = (isset($post["contact-address"])) ? $post["contact-address"] : "";
	$contactPostalCode = (isset($post["contact-postalCode"])) ? $post["contact-postalCode"] : "";
	$contactCity = (isset($post["contact-city"])) ? $post["contact-city"] : "";
	$contactCountry = (isset($post["contact-country"])) ? $post["contact-country"] : "";
	$contactPhoneHome = (isset($post["contact-phone-home"])) ? $post["contact-phone-home"] : "";
	$contactPhoneMobile = (isset($post["contact-phone-mobile"])) ? $post["contact-phone-mobile"] : "";
	$contactGender = (isset($post["contact-gender"])) ? $post["contact-gender"] : "";
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
	<label>Professeur référent</label>
	<select name="teacher">
		<?php foreach($teachers as $data){ ?>
			<option value="<?php echo $data['id']; ?>" <?php if($teacher == $data['id']){ ?>selected<?php } ?>><?php echo $data['personDetail']['firstName']; ?> - <?php echo $data['personDetail']['name']; ?></option>
		<?php } ?>
	</select><br />
	<label>Contact</label>
	<select id="contact-input" name="contact">
		<option value="0">Créer un nouveau contact</value>
		<?php foreach($contacts as $data){ ?>
			<option value="<?php echo $data['id']; ?>" <?php if($contact == $data['id']){ ?>selected<?php } ?>><?php echo $data['personDetail']['firstName']; ?> - <?php echo $data['personDetail']['name']; ?></option>
		<?php } ?>
	</select><br /><br />
	<div id="contact-student" style="display:none;">
		<h4>Nouveau contact</h4>
		<label>Nom du contact</label><input type="text" name="contact-name" value="<?php echo $contactName; ?>"/><br />
		<label>Prénom du contact</label><input type="text" name="contact-firstname" value="<?php echo $contactFirstname; ?>"/><br />
		<label>Email du contact</label><input type="text" name="contact-email" value="<?php echo $contactEmail; ?>"/><br />
		<label>Adresse du contact</label><input type="text" name="contact-address" value="<?php echo $contactAddress; ?>"/><br />
		<label>Code postal du contact</label><input type="number" name="contact-postalCode" value="<?php echo $contactPostalCode; ?>"/><br />
		<label>Ville du contact</label><input type="text" name="contact-city" value="<?php echo $contactCity; ?>"/><br />
		<label>Pays du contact</label><input type="text" name="contact-country" value="<?php echo $contactCountry; ?>"/><br />
		<label>Téléphone fixe du contact</label><input type="text" name="contact-phone-home" value="<?php echo $contactPhoneHome; ?>"/><br />
		<label>Téléphone mobile du contact</label><input type="text" name="contact-phone-mobile" value="<?php echo $contactPhoneMobile; ?>"/><br />
		<label>Sexe</label>
		<select name="contact-gender">
			<option value="0" <?php if($contactGender == '0'){ ?>selected<?php } ?>>Homme</option>
			<option value="1" <?php if($contactGender == '1'){ ?>selected<?php } ?>>Femme</option>
		</select><br />
		<br /><br />
	</div>
	<input type="hidden" name="token" value="<?php echo $session['token']; ?>" />
	<input type="submit" value="Enregistrer" />
</form>

<?php
?>		</div>
		<footer></footer>	
	</body>
</html>


<script type="text/javascript">
	$( document ).ready(function() {
		function checkInputContact()
		{
			if($('#contact-input').val() == "0")
			{
				$('#contact-student').css("display", "block");
			}
			else
			{
				$('#contact-student').css("display", "none");
			}
		}

		checkInputContact();

		$('#contact-input').change(function(){
			checkInputContact();
		});
	});
</script>
