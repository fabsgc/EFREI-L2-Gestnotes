<include src="include/header"/>

<?php
	$name = (isset($post["name"])) ? $post["name"] : $student["personDetail"]["name"];
	$firstname = (isset($post["firstname"])) ? $post["firstname"] : $student["personDetail"]["firstName"];
	$email = (isset($post["email"])) ? $post["email"] : $student["personDetail"]["email"];
	$address = (isset($post["address"])) ? $post["address"] : $student["personDetail"]["address"];
	$postalCode = (isset($post["postalCode"])) ? $post["postalCode"] : $student["personDetail"]["postalCode"];
	$city = (isset($post["city"])) ? $post["city"] : $student["personDetail"]["city"];
	$country = (isset($post["country"])) ? $post["country"] : $student["personDetail"]["country"];
	$phoneHome = (isset($post["phone-home"])) ? $post["phone-home"] : $student["personDetail"]["phoneHome"];
	$phoneMobile = (isset($post["phone-mobile"])) ? $post["phone-mobile"] : $student["personDetail"]["phoneMobile"];
	$dateBorn = (isset($post["date-born"])) ? $post["date-born"] : $student["personDetail"]["dateBorn"];
	$gender = (isset($post["gender"])) ? $post["gender"] : $student["personDetail"]["gender"];
	$teacher = (isset($post["teaher"])) ? $post["teacher"] : $student["teacher"]["id"];
	$contact = (isset($post["contact"])) ? $post["contact"] : $student["contact"]["id"];

	$contactName = (isset($post["contact-name"])) ? $post["contact-name"] : $student["contact"]["personDetail"]["name"];
	$contactFirstname = (isset($post["contact-firstname"])) ? $post["contact-firstname"] : $student["contact"]["personDetail"]["firstName"];
	$contactEmail = (isset($post["contact-email"])) ? $post["contact-email"] : $student["contact"]["personDetail"]["email"];
	$contactAddress = (isset($post["contact-address"])) ? $post["contact-address"] : $student["contact"]["personDetail"]["address"];
	$contactPostalCode = (isset($post["contact-postalCode"])) ? $post["contact-postalCode"] : $student["contact"]["personDetail"]["postalCode"];
	$contactCity = (isset($post["contact-city"])) ? $post["contact-city"] : $student["contact"]["personDetail"]["city"];
	$contactCountry = (isset($post["contact-country"])) ? $post["contact-country"] : $student["contact"]["personDetail"]["country"];
	$contactPhoneHome = (isset($post["contact-phone-home"])) ? $post["contact-phone-home"] : $student["contact"]["personDetail"]["phoneHome"];
	$contactPhoneMobile = (isset($post["contact-phone-mobile"])) ? $post["contact-phone-mobile"] : $student["contact"]["personDetail"]["phoneMobile"];
	$contactGender = (isset($post["contact-gender"])) ? $post["contact-gender"] : $student["contact"]["personDetail"]["gender"];
?>

<form method="post" action="">
	<label>Nom</label><input type="text" name="name" value="{$name}"/><br />
	<label>Prénom</label><input type="text" name="firstname" value="{$firstname}"/><br />
	<label>Email</label><input type="text" name="email" value="{$email}"/><br />
	<label>Adresse</label><input type="text" name="address" value="{$address}"/><br />
	<label>Code postal</label><input type="number" name="postalCode" value="{$postalCode}"/><br />
	<label>Ville</label><input type="text" name="city" value="{$city}"/><br />
	<label>Pays</label><input type="text" name="country" value="{$country}"/><br />
	<label>Téléphone fixe</label><input type="text" name="phone-home" value="{$phoneHome}"/><br />
	<label>Téléphone mobile</label><input type="text" name="phone-mobile" value="{$phoneMobile}"/><br />
	<label>Date de naissance</label><input type="text" name="date-born" value="{$dateBorn}"/><br />
	<label>Sexe</label>
	<select name="gender">
		<option value="0" <if condition="$gender == '0'">selected</if>>Homme</option>
		<option value="1" <if condition="$gender == '1'">selected</if>>Femme</option>
	</select><br />
	<label>Professeur référent</label>
	<select name="teacher">
		<foreach loop="$teachers as $data">
			<option value="{$data['id']}" <if condition="$teacher == $data['id']">selected</if>>{$data['personDetail']['firstName']} - {$data['personDetail']['name']}</option>
		</foreach>
	</select><br />
	<label>Contact</label>
	<select id="contact-input" name="contact">
		<foreach loop="$contacts as $data">
			<option value="{$data['id']}" <if condition="$contact == $data['id']">selected</if>>{$data['personDetail']['firstName']} - {$data['personDetail']['name']}</option>
		</foreach>
	</select><br /><br />
	<div id="contact-student" style="display:block;">
		<h4>Modifier le contact actuel</h4>
		<label>Nom du contact</label><input type="text" name="contact-name" value="{$contactName}"/><br />
		<label>Prénom du contact</label><input type="text" name="contact-firstname" value="{$contactFirstname}"/><br />
		<label>Email du contact</label><input type="text" name="contact-email" value="{$contactEmail}"/><br />
		<label>Adresse du contact</label><input type="text" name="contact-address" value="{$contactAddress}"/><br />
		<label>Code postal du contact</label><input type="number" name="contact-postalCode" value="{$contactPostalCode}"/><br />
		<label>Ville du contact</label><input type="text" name="contact-city" value="{$contactCity}"/><br />
		<label>Pays du contact</label><input type="text" name="contact-country" value="{$contactCountry}"/><br />
		<label>Téléphone fixe du contact</label><input type="text" name="contact-phone-home" value="{$contactPhoneHome}"/><br />
		<label>Téléphone mobile du contact</label><input type="text" name="contact-phone-mobile" value="{$contactPhoneMobile}"/><br />
		<label>Sexe</label>
		<select name="contact-gender">
			<option value="0" <if condition="$contactGender == '0'">selected</if>>Homme</option>
			<option value="1" <if condition="$contactGender == '1'">selected</if>>Femme</option>
		</select><br />
		<br /><br />
	</div>
	<input type="hidden" name="token" value="{$session['token']}" />
	<input type="submit" value="Enregistrer" />
</form>

<include src="include/footer"/>

<script type="text/javascript">
	$( document ).ready(function() {
		function checkInputContact()
		{
			if($('#contact-input').val() == "{$student['contact']['id']}")
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