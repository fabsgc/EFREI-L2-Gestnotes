<include src="include/header"/>
<ul>
	<li><strong>Nom</strong> : {$teacher['personDetail']['name']}</li>
	<li><strong>Prénom</strong> : {$teacher['personDetail']['firstName']}</li>
	<li><strong>Email</strong> : {$teacher['personDetail']['email']}</li>
	<li><strong>Adresse</strong> : {$teacher['personDetail']['address']}</li>
	<li><strong>Code postal</strong> : {$teacher['personDetail']['postalCode']}</li>
	<li><strong>Ville</strong> : {$teacher['personDetail']['city']}</li>
	<li><strong>Pays</strong> : {$teacher['personDetail']['country']}</li>
	<li><strong>Téléphone fixe</strong> : {$teacher['personDetail']['phoneHome']}</li>
	<li><strong>Téléphone mobile</strong> : {$teacher['personDetail']['phoneMobile']}</li>
	<li><strong>Date de naissance</strong> : {$teacher['personDetail']['dateBorn']}</li>
	<li>
		<strong>Sexe</strong> :
		<if condition="$teacher['personDetail']['gender'] == '0'">
			homme
		<else/>
			femme
		</if>
	</li>
</ul>
<include src="include/footer"/>