<include src="include/header"/>

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
		<option value="0">Créer un nouveau contact</value>
		<foreach loop="$contacts as $data">
			<option value="{$data['id']}" <if condition="$contact == $data['id']">selected</if>>{$data['personDetail']['firstName']} - {$data['personDetail']['name']}</option>
		</foreach>
	</select><br /><br />
	<div id="contact-student" style="display:none;">
		<h4>Nouveau contact</h4>
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