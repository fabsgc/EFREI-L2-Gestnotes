<include src="include/header"/>

<form method="get" action="">
	<input type="text" class="full" placeholder="Rechercher des élèves" name="search"/>
</form>

<a href="/admin/student/new/{$session['token']}" class="button right">Nouvel élève</a>
<table class="table">
	<thead>
		<tr>
			<th class="matricule">Matricule</th>
			<th>Nom</th>
			<th>Email</th>
			<th>Contact</th>
			<th>Professeur</th>
			<th class="action">Actions</th>
		<tr>
	</thead>
	<tbody>
		<foreach loop="$students as $data">
			<tr>
				<td>{$data['id']}</td>
				<td>
					<a href="/admin/student/see/{$data['id']}">{$data['personDetail']['firstName']} - {$data['personDetail']['name']}</a>
				</td>
				<td>{$data['personDetail']['email']}</td>
				<td>{$data['contact']['personDetail']['firstName']} - {$data['contact']['personDetail']['name']}</td>
				<td>{$data['teacher']['personDetail']['firstName']} - {$data['teacher']['personDetail']['name']}</td>
				<td class="action">
					<a href="/admin/student/edit/{$data['id']}/{$session['token']}"><span class="fa fa-pencil"></span></a>
					<a href="/admin/student/delete/{$data['id']}/{$session['token']}"><span class="fa fa-times"></span></a>
					<a href="/admin/student/report/generate/{$data['id']}/{$session['token']}"><span class="fa fa-university"></span></a>
				</td>
			</tr>
		</foreach>
	<tbody>
</table>

<include src="include/footer"/>