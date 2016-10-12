<include src="include/header"/>

<a href="/admin/student/report/generate/{$student['id']}/{$session['token']}" class="button right">Editer le bulletin de l'élève</a>
<div class="clear-right"></div>
<h4>Elève</h4>
<ul>
	<li><strong>Nom</strong> : {$student['personDetail']['name']}</li>
	<li><strong>Prénom</strong> : {$student['personDetail']['firstName']}</li>
	<li><strong>Email</strong> : {$student['personDetail']['email']}</li>
	<li><strong>Adresse</strong> : {$student['personDetail']['address']}</li>
	<li><strong>Code postal</strong> : {$student['personDetail']['postalCode']}</li>
	<li><strong>Ville</strong> : {$student['personDetail']['city']}</li>
	<li><strong>Pays</strong> : {$student['personDetail']['country']}</li>
	<li><strong>Téléphone fixe</strong> : {$student['personDetail']['phoneHome']}</li>
	<li><strong>Téléphone mobile</strong> : {$student['personDetail']['phoneMobile']}</li>
	<li><strong>Date de naissance</strong> : {$student['personDetail']['dateBorn']}</li>
	<li>
		<strong>Sexe</strong> :
		<if condition="$student['personDetail']['gender'] == '0'">
			homme
		<else/>
			femme
		</if>
	</li>
	<li>
		<strong>Professeur référent</strong> : 
		{$student['teacher']['personDetail']['firstName']}  
		{$student['teacher']['personDetail']['name']}
	</li>
</ul>
<h4>Responsable</h4>
<ul>
	<li><strong>Nom</strong> : {$student['contact']['personDetail']['name']}</li>
	<li><strong>Prénom</strong> : {$student['contact']['personDetail']['firstName']}</li>
	<li><strong>Email</strong> : {$student['contact']['personDetail']['email']}</li>
	<li><strong>Adresse</strong> : {$student['contact']['personDetail']['address']}</li>
	<li><strong>Code postal</strong> : {$student['contact']['personDetail']['postalCode']}</li>
	<li><strong>Ville</strong> : {$student['contact']['personDetail']['city']}</li>
	<li><strong>Pays</strong> : {$student['contact']['personDetail']['country']}</li>
	<li><strong>Téléphone fixe</strong> : {$student['contact']['personDetail']['phoneHome']}</li>
	<li><strong>Téléphone mobile</strong> : {$student['contact']['personDetail']['phoneMobile']}</li>
	<li>
		<strong>Sexe</strong> :
		<if condition="$student['contact']['personDetail']['gender'] == '0'">
			homme
		<else/>
			femme
		</if>
	</li>
</ul>

<include src="include/footer"/>